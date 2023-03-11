#include "stdafx.h"
#include "Error.h"

namespace Error {
	/*серии ошибок 0 - 99 - системные ошибки
				   100 - 109 - ошибки параметров
				   110 - 119 - ошбики открытия и чтения файлов
	*/
	ERROR errors[ERROR_MAX_ENTRY] = //таблица ошибок
	{
		ERROR_ENTRY(0, "недопустимый код ошибки"), // код ошибки вне диапазона 0 - ERROR_MAX_ENTRY
		ERROR_ENTRY(1, "системный сбой"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Параметр -in должен быть задан"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "Превышена длина входного параметра"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "ошибка при открити файла с исходным кодом (-in)"),
		ERROR_ENTRY(111, "недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(112, "ошибка при создании файла протокола(-in)"),
		ERROR_ENTRY(113,"ошибка при открити файла"), 
		ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115), ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117),
		ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119), ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140),
		ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200, "Лексическая ошибка: Лексема не распознана"),
		ERROR_ENTRY(201 ,"Лексическая ошибка: превышен допустимый размер лексической таблицы"),
		ERROR_ENTRY(202, "Лексическая ошибка: элемент не может быть добавлен, т.к. выходит за пределы допустимого размера таблицы"),
		ERROR_ENTRY(203, "Лексическая ошибка: превышен допустимый размер таблицы идентефикаторов"),
		ERROR_ENTRY_NODEF(204), ERROR_ENTRY_NODEF(205),
		ERROR_ENTRY_NODEF(206), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209), ERROR_ENTRY_NODEF10(210),
		ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250), ERROR_ENTRY_NODEF10(260),
		ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "Семантическая ошибка: Повторное определение идентификатора"),
		ERROR_ENTRY(301, "Семантическая ошибка: Отсутствие точки входа main"),
		ERROR_ENTRY(302, "Семантическая ошибка: Наличие более одной точки входа main"),
		ERROR_ENTRY(303, "Семантическая ошибка: Тип возвращаемого значения не соответствует возвращаемому значению"),
		ERROR_ENTRY(304, "Семантическая ошибка: Неверное количество параметров"),
		ERROR_ENTRY(305, "Семантическая ошибка: В функции не ожидаются аргументы указанного типа"),
		ERROR_ENTRY(306, "Семантическая ошибка: Превышение допустимого количества параметров функции"),
		ERROR_ENTRY(307, "Семантическая ошибка: Превышение допустимого размера строкового литерала "),
		ERROR_ENTRY(308, "Семантическая ошибка: Пустой строковый литерал является недопустимой конструкцией"),
		ERROR_ENTRY(309, "Семантическая ошибка: Недопустимое целочисленное значение"),
		ERROR_ENTRY(310, "Семантическая ошибка: Отсутствие типа при объявлении"),
		ERROR_ENTRY(311, "Семантическая ошибка: Превышение длины идентификатора"),
		ERROR_ENTRY(312, "Семантическая ошибка: Вызов неопределенного идентификатора"),
		ERROR_ENTRY(313, "Семантическая ошибка: Попытка определения идентификатора вне тела функции или процедуры"),
		ERROR_ENTRY(314, "Семантическая ошибка: Попытка деления на 0"),
		ERROR_ENTRY(315, "Семантическая ошибка: Несовпадение типов в выражении"),
		ERROR_ENTRY(316, "Семантическая ошибка: Несовпадение типов в выражении, данное выражение поддерживает только логический тип"),
		ERROR_ENTRY(317, "Семантическая ошибка: Превышение допустимого размера символьного литерала"),
		ERROR_ENTRY(318, "Семантическая ошибка: Неверная расстановка кавычек"),
		ERROR_ENTRY(319, "Семантическая ошибка: Несоответствие типов в условии"),
		ERROR_ENTRY(320, "Семантическая ошибка: В статических функциях в качестве аргумента должны быть только идентификаторы"),
		ERROR_ENTRY(321, "Семантическая ошибка: Copystr ничего не возвращает, проверьте правильность выражения"),
		ERROR_ENTRY_NODEF(322),ERROR_ENTRY_NODEF(323),ERROR_ENTRY_NODEF(324),ERROR_ENTRY_NODEF(325),ERROR_ENTRY_NODEF(326),ERROR_ENTRY_NODEF(327),ERROR_ENTRY_NODEF(328),ERROR_ENTRY_NODEF(329),
		ERROR_ENTRY_NODEF10(330), ERROR_ENTRY_NODEF10(340), ERROR_ENTRY_NODEF10(350), ERROR_ENTRY_NODEF10(360),
		ERROR_ENTRY_NODEF10(370), ERROR_ENTRY_NODEF10(380), ERROR_ENTRY_NODEF10(390),
		ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "Семантическая ошибка: Неверная структура программы"),
		ERROR_ENTRY(601, "Синтаксическая ошибка: Не найден список параметров функции"),
		ERROR_ENTRY(602, "Синтаксическая ошибка: Ошибка в теле функции"),
		ERROR_ENTRY(603, "Синтаксическая ошибка: Ошибка в теле процедуры"),
		ERROR_ENTRY(604, "Синтаксическая ошибка: Ошибка в списке параметров функции"),
		ERROR_ENTRY(605, "Синтаксическая ошибка: Ошибка в вызове функции"),
		ERROR_ENTRY(606, "Синтаксическая ошибка: Ошибка в списке параметров функции"),
		ERROR_ENTRY(607, "Синтаксическая ошибка: Ошибка при констуировании условного выражения"),
		ERROR_ENTRY(608, "Синтаксическая ошибка: Ошибка в теле условного выражения"),
		ERROR_ENTRY(609, "Синтаксическая ошибка: Ошибка в условии условного выражения"),
		ERROR_ENTRY(610, "Синтаксическая ошибка: Неверный условный оператор"),
		ERROR_ENTRY(611, "Синтаксическая ошибка: Неверный арифметический оператор"),
		ERROR_ENTRY(612, "Синтаксическая ошибка: Неверное выражение. Ожидаются идентификаторы и литералы"),
		ERROR_ENTRY(613, "Синтаксическая ошибка: Ошибка в правостороннем выражении"),
		ERROR_ENTRY(614, "Синтаксическая ошибка: Недопустимая синтаксическая конструкция"),
		ERROR_ENTRY(615, "Синтаксическая ошибка: Недопустимая синтаксическая конструкция в теле условного выражения"),
		ERROR_ENTRY_NODEF(616), ERROR_ENTRY_NODEF(617), ERROR_ENTRY_NODEF(618),	ERROR_ENTRY_NODEF(619),
		ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640), ERROR_ENTRY_NODEF10(650),
		ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680), ERROR_ENTRY_NODEF10(690),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};
	ERROR geterror(int id) {
		if (id > 0 && id < ERROR_MAX_ENTRY) return errors[id];
		else return errors[0];
	}
	ERROR geterrorin(int id, int line = -1, int col = -1) {
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			return errors[id];
		}
		else {
			return errors[0];
		}
	}
}