#pragma once
#include "stdafx.h"



#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3
static int FST_TRACE_n = -1;
static char rbuf[205], sbuf[205], lbuf[1024];

#define MFST_TRACE_START	stream_out << std::setw(4) << std::left << "���" << ": "\
							<< std::setw(30) << std::left << "�������"\
							<< std::setw(30) << std::left << "������� �����"\
							<< std::setw(20) << std::left << "����"\
							<< std::endl;

#define MFST_TRACE1			stream_out << std::setw(4) << std::left << ++FST_TRACE_n << ": " \
							<< std::setw(30) << std::left << rule.getCRule(rbuf, nrulechain)\
							<< std::setw(30) << std::left << getCLenta(lbuf, lenta_position)\
							<< std::setw(20) << std::left << getCSt(sbuf)\
							<< std::endl;

#define MFST_TRACE2			stream_out << std::setw(4) << std::left << FST_TRACE_n << ": "\
							<< std::setw(30) << std::left << " "\
							<< std::setw(30) << std::left << getCLenta(lbuf, lenta_position)\
							<< std::setw(20) << std::left << getCSt(sbuf)\
							<< std::endl;

#define MFST_TRACE3			stream_out << std::setw(4) << std::left << ++FST_TRACE_n << ": "\
							<< std::setw(30) << std::left << " "\
							<< std::setw(30) << std::left << getCLenta(lbuf, lenta_position)\
							<< std::setw(20) << std::left << getCSt(sbuf)\
							<< std::endl;

#define MFST_TRACE4(c)		stream_out << std::setw(4) << std::left << ++FST_TRACE_n << ": " << std::setw(20) << std::left << c << std::endl;
#define MFST_TRACE5(c)		stream_out << std::setw(4) << std::left << FST_TRACE_n << ": " << std::setw(20) << std::left << c << std::endl;
#define MFST_TRACE6(c, k)	stream_out << std::setw(4) << std::left << FST_TRACE_n << ": " << std::setw(20) << std::left << c << k << std::endl;
#define MFST_TRACE7			stream_out << std::setw(4) << std::left << state.lenta_position << ": "\
							<< std::setw(20) << std::left << rule.getCRule(rbuf, state.nrulechain)\
							<< std::endl;

class my_stack_SHORT :public std::stack<short> {	// ���� ��������
public:
	using std::stack<short>::c;
};

typedef my_stack_SHORT MFSTSTSTACK;
namespace MFST {
	struct MfstState {			// ��������� �������� (��� ����������)
		short lenta_position;	// ������� �� �����
		short nrule;			// ����� �������� �������
		short nrulechain;		// ����� ������� �������, �������� �������
		MFSTSTSTACK st;			// ���� ��������
		MfstState();
		MfstState(
			short pposition,	// ������� �� �����
			MFSTSTSTACK pst,	// ���� ��������
			short pnrulechain	// ����� ������� �������, �������� �������
		);
		MfstState(
			short pposition,	// ������� �� �����
			MFSTSTSTACK pst,	// ���� ��������
			short pnrule,		// ���� ��������
			short pnrulechain	// ����� ������� �������, �������� �������
		);
	};

	struct Mfst {				// ���������� �������
		enum RC_STEP {			// ��� �������� ������� step
			NS_OK,				// ������� ������� � �������, ������� �������� � ����
			NS_NORULE,			// �� ������� ������� ���������� (������ � ����������)
			NS_NORULECHAIN,		// �� ������� ���������� ������� ������� (������ � �������� ����)
			NS_ERROR,			// ����������� �������������� ������ ����������
			TS_OK,				// ���. ������ ����� == ������� �����, ������������ �����, pop �����
			TS_NOK,				// ���. ������ ����� != ������� �����, �������������� ���������
			LENTA_END,			// ������� ������� ����� >= lenta_size
			SURPRISE,			// ����������� ��� �������� (������ � step)
		};

		struct MfstDiagnosis {		// �����������
			short lenta_position;	// ������� �� �����
			RC_STEP rc_step;		// ��� ���������� ����
			short nrule;			// ����� �������
			short nrule_chain;		// ����� ������� �������
			MfstDiagnosis();
			MfstDiagnosis(				// �����������
				short plenta_position,	// ������� �� �����
				RC_STEP prc_step,		// ��� ���������� ����
				short pnrule,			// ����� �������
				short pnrule_chain		// ����� ������� �������
			);
		}diagnosis[MFST_DIAGN_NUMBER];	// ��������� ����� �������� ���������

		class my_stack_MfstState :public std::stack<MfstState> {	// ���� ��������
		public:
			using std::stack<MfstState>::c;
		};

		GRBALPHABET* lenta;				// ���������������� (TS/NS) ����� (�� LEX)
		short lenta_position;			// ������� ������� �� �����
		short nrule;					// ����� �������� �������
		short nrulechain;				// ����� ������� �������, �������� �������
		short lenta_size;				// ������ �����
		GRB::Greibach greibach;			// ���������� �������
		LT::LexTable lex;				// ��������� ������ ������������ �����������
		MFSTSTSTACK st;					// ���� ��������
		my_stack_MfstState storestate;	// ���� ��� ���������� ���������
		Mfst();
		Mfst(
			LT::LexTable& plex,			// ��������� ������ ������������ �����������
			GRB::Greibach pgreibach		// ���������� �������
		);
		char* getCSt(char* buf);		// �������� ���������� �����
		char* getCLenta(char* buf, short pos, short n = 25);	// �����: n �������� � pos
		char* getDiagnosis(short n, char* buf);		// �������� n-�� ������ ����������� ��� 0x00
		bool savestate(std::ostream& stream_out);	// ��������� ��������� ��������
		bool resetstate(std::ostream& stream_out);	// ������������ ��������� ��������
		bool push_chain(				// ��������� ������� ������� � ����	
			GRB::Rule::Chain chain		// ������� �������
		);
		RC_STEP step(std::ostream& stream_out);					// ��������� ��� ��������
		bool start(std::ostream& stream_out);					// ��������� �������
		bool saveddiagnosis(
			RC_STEP pprc_step			// ��� ���������� ����
		);
		void printrules(std::ostream& stream_out);				// ������� ������������������ ������	

		struct Deducation {				// �����
			short size;					// ���������� ������ ����������
			short* nrules;				// ������ ������ ����������
			short* nrulechains;			// ������ ������� ������ ���������� (nrules)
			Deducation() {
				size = 0;
				nrules = 0;
				nrulechains = 0;
			}
		}deducation;

		bool savededucation();			// ��������� ������ ������
	};

	void SyntaxCheck(Lexical::Lexic lex, Log::LOG log, std::ostream& stream_out);
}