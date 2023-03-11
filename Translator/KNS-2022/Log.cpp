#include "stdafx.h"

namespace Log {
	LOG getlog(wchar_t logfile[]) {

		LOG log;
		log.stream = new std::ofstream;
		wcscpy_s(log.logfile, logfile);
		log.stream->open(log.logfile);

		if (log.stream->fail()) {
			throw ERROR_THROW(112)
		}
		else {
			return log;
		}

	}

	void WriteLine(LOG log, char* c, ...) {
		char** pnt = &c, sentence[100] = "";
		while (*pnt != "") {
			strcat_s(sentence, *pnt);
			*pnt++;
		}
		*log.stream << sentence;
	}

	void WriteLine(LOG log, wchar_t* c, ...) {
		wchar_t** pnt = &c;
		char sentence[20] = "";
		char result[100] = "";

		while (*pnt != L"") {
			wcstombs_s(0, sentence, *pnt, 20);
			strcat_s(result, sentence);
			*pnt++;
		}
		*log.stream << result;
	}

	void WriteLog(LOG log) {
		tm* date;
		char phrase[100] = "";
		time_t timer;
		time(&timer);
		date = localtime(&timer);
		strftime(phrase, 100, "- - - - Протокол - - - - %d.%m.%Y   %H:%M:%S ", date);
		*log.stream << phrase;
	}

	void WriteParm(LOG log, Parm::PARM parm) {
		char param[20];
		*log.stream << "\n\n- - - - Параметры - - - -\n";
		wcstombs_s(0, param, parm.log, 20);
		*log.stream << "-log: " << param << std::endl;
		wcstombs_s(0, param, parm.out, 20);
		*log.stream << "-out: " << param << std::endl;
		wcstombs_s(0, param, parm.in, 20);
		*log.stream << "-in: " << param << std::endl;
	}

	void WriteIn(LOG log, In::IN in) {
		*log.stream << "\n- - - - Исходные данные - - - -\n";
		*log.stream << in.text << std::endl;
		*log.stream << "Количество символов: " << in.size << std::endl;
		*log.stream << "Проигнорировано    : " << in.ignor << std::endl;
		*log.stream << "Количество строк   : " << in.lines << std::endl;
	}

	void WriteError(LOG log, Error::ERROR error) {
		*log.stream << "Ошибка " << error.id << ": " << error.message << " Позиция " << error.inext.line << " строка " << error.inext.col << std::endl;
	}

	void Close(LOG log) {
		log.stream->close();
	}
}