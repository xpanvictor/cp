// #include <bits/stdc++.h>

// using namespace std;

// string ltrim(const string &);
// string rtrim(const string &);
// vector<string> split(const string &);

// double find_median(vector<int> &arr)
// {
//     if (arr.empty())
//         return 0.0;
//     sort(arr.begin(), arr.end());
//     int s = arr.size();
//     if (s % 2 == 0)
//         return (arr[s / 2 - 1] + arr[s / 2]) / 2.0;
//     else
//         return arr[s / 2];
// }

// /*
//  * Complete the 'activityNotifications' function below.
//  *
//  * The function is expected to return an INTEGER.
//  * The function accepts following parameters:
//  *  1. INTEGER_ARRAY expenditure
//  *  2. INTEGER d
//  */

// int activityNotifications(vector<int> expenditure, int d)
// {
//     int count = 0;

//     for (auto cb = expenditure.begin() + d; cb != expenditure.end(); ++cb)
//     {
//         if (cb - expenditure.begin() < d)
//             continue;
//         auto pb = cb - d;
//         vector sl(pb, cb);
//         double wd_md = find_median(sl);
//         cout << "curr:" << *cb << "p:" << *pb << "-" << *cb << "med:" << wd_md << "\n";
//         if (*cb >= 2 * wd_md)
//             count++;
//     }
//     return count;
// }

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string first_multiple_input_temp;
//     getline(cin, first_multiple_input_temp);

//     vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

//     int n = stoi(first_multiple_input[0]);

//     int d = stoi(first_multiple_input[1]);

//     string expenditure_temp_temp;
//     getline(cin, expenditure_temp_temp);

//     vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

//     vector<int> expenditure(n);

//     for (int i = 0; i < n; i++)
//     {
//         int expenditure_item = stoi(expenditure_temp[i]);

//         expenditure[i] = expenditure_item;
//     }

//     int result = activityNotifications(expenditure, d);

//     fout << result << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str)
// {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

//     return s;
// }

// string rtrim(const string &str)
// {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end());

//     return s;
// }

// vector<string> split(const string &str)
// {
//     vector<string> tokens;

//     string::size_type start = 0;
//     string::size_type end = 0;

//     while ((end = str.find(" ", start)) != string::npos)
//     {
//         tokens.push_back(str.substr(start, end - start));

//         start = end + 1;
//     }

//     tokens.push_back(str.substr(start));

//     return tokens;
// }
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

double find_median(vector<int> &arr, int d)
{
    // find cummulative sum; take note of even median too
    int cum = 0;
    int m1 = -1, m2 = -1;
    int pos1 = (d + 1) / 2;
    int pos2 = (d % 2 == 0) ? (d / 2 + 1) : pos1;
    for (int i = 0; i < arr.size(); ++i)
    {
        cum += arr[i];
        if (m1 == -1 && cum >= pos1)
        {
            m1 = i;
        };
        if (m2 == -1 && cum >= pos2)
        {
            m2 = i;
            break;
        }
    }
    return (m1 + m2) / 2.0;
}

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

/// Using counting sort
int activityNotifications(vector<int> expenditure, int d)
{
    int notifications{0};
    vector<int> count(201);
    // count first d expenditure
    for (int i = 0; i < d; ++i)
        count[expenditure[i]]++;

    // now median
    for (int i = d; i < expenditure.size(); ++i)
    {
        double median = find_median(count, d);
        cout << "elm1 " << median << "val " << expenditure[i] << "\n";
        if (expenditure[i] >= 2 * median)
            notifications++;
        count[expenditure[i - d]]--;
        count[expenditure[i]]++;
    }
    return notifications;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++)
    {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";
    cout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
