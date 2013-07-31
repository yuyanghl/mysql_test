//============================================================================
// Name        : mysql_test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    // Get database access parameters from command lin
    // Connect to the sample database.
    int a;
    mysqlpp::Connection conn(false);
    if (conn.connect("my_db", "localhost", "root", "9865"))
    {
        mysqlpp::Query query = conn.query("select * from tb1");
        if (mysqlpp::StoreQueryResult res = query.store())
        {
            cout << "We have:" << endl;
            for(size_t i = 0; i < res.num_fields(); i++)
            {
            	cout<<"\t"<<res.field_name(i);
            }
            cout<<endl;
            for (size_t i = 0; i < res.num_rows(); ++i)
            {
            	for(size_t j = 0; j < res.num_fields(); ++j)
            	{
            		cout << '\t' << res[i][j];
            	}
            	cout<<endl;
            }

        }
        else
        {
            cerr << "Failed to get item list: " << query.error() << endl;
            return 1;
        }

        return 0;
    }
    else
    {
        cerr << "DB connection failed: " << conn.error() << endl;
        return 1;
    }
}
