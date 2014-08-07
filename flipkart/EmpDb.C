#include "../template.h"

vector < pair < string, vector <string> > > reportees; // Adjacency list to store the list of directs;

class Employee
{
	public :
		int id; // primary_key
		string name, email, designation, reportsTo;

		Employee(int _id, string _email, string _name, string _designation, string _reportsTo)
		{
			// cout << creating employee
			id = _id; 
			email = _email;
			name = _name, designation = _designation, reportsTo = _reportsTo;
		}

		void print()
		{
			cout << "Id : " << id << endl;
			cout << "Name : " << name << endl;
			cout << "Reports to : " << reportsTo << endl;
			cout << "Email Id " << email << endl;
		}

};

vector <Employee> database;
map <string, bool> seen;

void addEmp(Employee e)
{
	if(!seen[e.name]) // Enter only if its a new employee information
	{
		seen[e.name] = true;
		database.pb(e);
		string s = e.name;
		cout << e.name << " reports to " << e.reportsTo << endl;
		if(!seen[e.reportsTo]) // Manager not added before
		{
			// Create an entry for him in the hash table and add his reportee.
			//seen[e.reportsTo] = true;
			vector <string> names;
			names.pb(e.name);
			reportees.pb(mkp(e.reportsTo, names));
		}
		else	// already an entry is there in the hash table, add to the adjacency list of existing manager
		{
			REP(i, reportees.sz)
			{
				if(reportees[i].first == e.reportsTo)
				{
					// found the entry, add it
					reportees[i].second.pb(e.name);
					break; // gracefully exit
				}
			}
		}
	}
	else
		cout << "Employee exists already! " << endl;
}

int main()
{
	string name, email, des, manager;
	int id;

	//Employee e1(1, "v@x.com", "Venkat", "SDE-2", "XYZ");
	//Employee e2(2, "v@x.com", "Venkat", "SDE-2", "XYZ");
	//database.pb(e1);
	//database.pb(e2);
	cout << "Please add employee information : (Enter 0 to exit)" << endl;
	cout << "Enter 1 to add an employee " << endl;
	cout << "Enter 2 to fetch details " << endl;
	cout << "Enter 3 for prefix search " << endl;
	int ch;cin >> ch;
	while(ch)
	{
		if(ch == 1) {
			cout << "Id : " <<endl;
			cin >> id;
			cout << "Name : " << endl;
			cin >> name;
			cout << "Email " << endl;
			cin >> email;
			cout << "Designation " << endl;
			cin >> des;
			cout << "Manager " << endl;
			cin >> manager;
			Employee e(id, email, name, des, manager);
			addEmp(e);
		}
		if(ch == 2)
		{
			string e;
			cout << "Enter the Employee name to fetch details from database" << endl;
			cin >> e;
			if(!seen[e])
				cout << "Oops! Error 404 Employee NOT found! :) " << endl;
			else
			{
				REP(i, database.sz)
				{
					if(database[i].name == e)
					{
						map <string, bool > visited;
						cout << "Employee found! Details below " << endl;


						//BFS
						

						queue < string > Q;
						Q.push(e);
						REP(k, reportees.sz)
						{
							if(reportees[k].first == e)
							{
								REP(m, reportees[k].second.sz)
								{
									Q.push(reportees[k].second[m]);
								}
								break;
							}
						}

						vector <string> emp;
						while(!Q.empty())
						{
							string v = Q.front();
							Q.pop();
							visited[v] = true;
							REP(xx, database.sz)
							{
								if(database[xx].name == v)
								database[xx].print();
							}

							// Enqueue the adjacency list
							if(!visited[v])
							{
								// Find the entry in reportee list;
								REP(y, reportees.sz)
								{
									if(reportees[y].first == v)
									{
										REP(z, reportees[y].second.sz)
										Q.push(reportees[y].second[z]);
									}
								}
							}

						}
					}
				}
			}
		}
		if(ch == 3)
		{
			cout <<"Search for an employee" << endl;
			string pref; cin >> pref;
			REP(i, database.sz)
			{
				if(database[i].name.substr(0, pref.sz) == pref)
				database[i].print();
			}
		}
		cout << "Please add employee information : (Enter 0 to exit)" << endl;
		cout << "Enter 1 to add an employee " << endl;
		cout << "Enter 2 to fetch details " << endl;
			cout << "Enter 3 for prefix search " << endl;
	cin >> ch;
	}
	//REP(i, database.sz)
	//database[i].print();

	return 0;
}
