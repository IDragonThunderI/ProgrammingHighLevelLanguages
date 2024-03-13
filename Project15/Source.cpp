#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Train
{
	int number;
	wchar_t station[30];
	wchar_t time_start[6];
	wchar_t time_in_way[6];
	wchar_t ticket[4];
};

int main() {
	std::string loc(strcat(setlocale(LC_ALL, ""), " > nul"));
    system(loc.replace(0, loc.find('.') + 1, "chcp ").c_str());

	Train a;
	int n;
	
	wfstream f;
	f.open("f.dat", wios::in | wios::out | wios::trunc);
	if (!f.is_open()) {
		wcout << L"file error!";
		exit(1);
	}

	wcout << L"Введите количество рейсов: ";
	wcin >> n;
	
	for (int i = 0; i < n; i++) {
		wcout << L"\nВведите номер поезда: ";
		wcin >> a.number;
		wcout << L"\nВведите пункт прибытия: ";
		wcin >> a.station;
		wcout << L"\nВведите время отправки (Пример: 06:00; 09:30; 15:00): ";
		wcin >> a.time_start;
		wcout << L"\nВведите время в пути: ";
		wcin >> a.time_in_way;
		wcout << L"\nВведите наличие билетов (Да или Нет): ";
		wcin >> a.ticket;
		wcout << endl;
		
		f << a.number << L"\n" << a.station << L"\n" << a.time_start << L"\n" << a.time_in_way << L"\n" << a.ticket << L"\n";
	}
	
	wchar_t searching_station[30];
	wchar_t searching_time_A[6];
	wchar_t searching_time_B[6];
	wcout << L"\nВведите искомый пункт прибытия: ";
	wcin >> searching_station;
	wcout << L"\nВведите начало интервала искомого времени отправки (Пример: 06:00; 09:30; 15:00): ";
	wcin >> searching_time_A;
	wcout << L"\nВведите конец интервала искомого времени отправки (Пример: 06:00; 09:30; 15:00): ";
	wcin >> searching_time_B;

	f.seekp(0);
	
	wcout << L"\n\nНайденные подходящие рейсы: " << endl;
	for (int i = 0; i < n; i++) {
		f >> a.number >> a.station >> a.time_start >> a.time_in_way >> a.ticket;
		
		if (wcscmp(searching_station, a.station) == 0 && wcscmp(searching_time_A, a.time_start) <= 0 && wcscmp(searching_time_B, a.time_start) >= 0) {
			wcout << a.station << L"; " << a.number << L" => " << a.time_start << endl;
		}
	}

	int searching_number;
	wcout << L"\n\nВведите искомый номер поезда: ";
	wcin >> searching_number;

	f.seekp(0);

	for (int i = 0; i < n; i++) {
		f >> a.number >> a.station >> a.time_start >> a.time_in_way >> a.ticket;

		if (searching_number == a.number) {
			wcout << L"\nНаличие билетов на выбранный рейс: " << endl << searching_station << L"; " << searching_number << L" => " << a.ticket << endl << endl;
		}
	}
	
	f.close();
	
	return 0;
}