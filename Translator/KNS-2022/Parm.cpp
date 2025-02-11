#include "stdafx.h"

namespace Parm {

	PARM getparm(int argc, wchar_t* argv[])
	{
		PARM parm;

		bool in_check = 0, out_check = 0, log_check = 0;

		for (int i = 1; i < argc; i++) {
			if (wcslen(argv[i]) > PARM_MAX_SIZE) throw ERROR_THROW(104);
			if (wcsstr(argv[i], PARM_IN)) {
				wcscpy_s(parm.in, argv[i] + wcslen(PARM_IN));
				in_check = 1;
			}
			if (wcsstr(argv[i], PARM_OUT)) {
				wcscpy_s(parm.out, argv[i] + wcslen(PARM_OUT));
				out_check = 1;
			}
			if (wcsstr(argv[i], PARM_LOG)) {
				wcscpy_s(parm.log, argv[i] + wcslen(PARM_LOG));
				log_check = 1;
			}
		}

		if (in_check == 0) throw ERROR_THROW(100)

			if (out_check == 0) {
				wcscpy_s(parm.out, parm.in);
				wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
			}

		if (log_check == 0) {
			wcscpy_s(parm.log, parm.in);
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}

		return parm;
	}
};
