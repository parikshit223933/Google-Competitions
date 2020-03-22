#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
struct libr {
	int sign_up_time;
	int total_book_score;
	int library_id;
	int total_number_of_books;
	int number_of_books_per_day;
	int* book_ids;
};
void shifter(int* arr, int n, int index)
{
	int element = arr[index];
	for (int i = index; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = element;
}
bool sorter_algo(libr a, libr b)
{
	/*
		priority order
	1. total book score
	2. number of books per day
	3. sign up time
	4. total number of books
	*/
	if (a.total_book_score > b.total_book_score)
	{
		if (a.number_of_books_per_day > b.number_of_books_per_day)
		{
			if (a.sign_up_time < b.sign_up_time)
			{
				if (a.total_number_of_books > b.total_number_of_books)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	freopen("a_example.txt", "r", stdin);
	freopen("a.txt", "w", stdout);
	int b;//number of different books
	cin >> b;
	int l;//number of libraries
	cin >> l;
	int d;//number of days
	cin >> d;



	int* bookscore = new int[b];
	for (int i = 0; i < b; i++)
	{
		cin >> bookscore[i];
	}


	int library = 0;
	libr* tripplets = new libr[l];
	while (library < l)
	{
		int n;//the number of books
		int t;//number of days for library sign up process
		int m;//the number of books that can be shipped to the scanning facility per day once the library is signed up
		cin >> n >> t >> m;
		/////////////////////////////////////////////////////////////////first section
		int* bookid = new int[n];
		int book_score_for_this_library = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> bookid[i];
			book_score_for_this_library = bookscore[bookid[i]];
		}
		tripplets[library].sign_up_time = t;
		tripplets[library].library_id = library;
		tripplets[library].total_book_score = book_score_for_this_library;
		tripplets[library].total_number_of_books = n;
		tripplets[library].number_of_books_per_day = m;
		tripplets[library].book_ids = bookid;
		library++;
	}
	sort(tripplets, tripplets + l, sorter_algo);



	cout << l << endl;
	map<int, int>m;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < tripplets[i].total_number_of_books; j++)
		{
			if (m[tripplets[i].book_ids[j]] > 1)
			{
				shifter(tripplets[i].book_ids, tripplets[i].total_number_of_books, j);
			}
			else
			{
				m[tripplets[i].book_ids[j]] += 1;
			}
		}
		cout << tripplets[i].library_id << " " << tripplets[i].total_number_of_books << endl;

		for (int j = 0; j < tripplets[i].total_number_of_books; j++)
		{
			cout << tripplets[i].book_ids[j] << " ";
		}
		cout << endl;
	}
}

//order in which the library is signed up matters
//SUBMISSION
/*
A-the number of libraries to sign up
describe the order i want them to start the sign up process
decs of each library must contain two lines
the first line contains the id of the library and the number of books to be scanned from the library
ids of the books to be scanned from that library

*/