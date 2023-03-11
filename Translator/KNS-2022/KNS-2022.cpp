#include "stdafx.h"

using namespace std;
char JsFile[] = "..\\Code\\JavaScript\\GeneratedJSCode.js";
void Logger(std::ostream& stream, Error::ERROR e)
{
    stream << "������ " << e.id << ": " << e.message << endl;
    stream << "������: " << e.inext.col << " �������: " << e.inext.line;
}

int _tmain(int argc, _TCHAR* argv[]) {

    setlocale(LC_ALL, "rus");

    Log::LOG log;
    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);
        log = Log::getlog(parm.log);
        wcout << " -in: " << parm.in << " \n-out: " << parm.out << " \n-log: " << parm.log << endl << endl;
    }
    catch (Error::ERROR e)
    {
        cout << "������ " << e.id << ": " << e.message << endl;
        exit(-1);
    }

    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);
        In::IN in = In::getin(parm.in);

        ofstream file(parm.out);
        cout << in.text << endl;
        file << in.text << endl;
        Lexical::Lexic tables = Lexical::LexicalAnalize(in);
        for (int i = 0; i < tables.Lex.size; i++)
        {
            cout << tables.Lex.table[i].lexema[0];
        }

        cout << endl << endl;
        Lexical::Logger(*log.stream);

        MFST::SyntaxCheck(tables, log, *log.stream);

        Semantic::semanticsCheck(tables.Lex, tables.Id);
        Generator::generateCode(tables, JsFile);
    }
    catch (Error::ERROR e)
    {
        if (e.id < 200)
        {
            cout << "�������� ���������� ������, ����������� ��� ����, ��� ��������� ��������� ����������";
        }
        if (e.id >= 200 && e.id < 300)
        {
            cout << "�������� ����������� ������, ����������� ��� ����, ��� ��������� ��������� ����������";
        }
        if (e.id >= 300 && e.id < 400)
        {
            cout << "�������� ������������� ������, ����������� ��� ����, ��� ��������� ��������� ����������";
        }
        Logger(*log.stream, e);
    }

    return 0;
};