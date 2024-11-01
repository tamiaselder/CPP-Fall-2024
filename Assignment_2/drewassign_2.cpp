#include <vector>
#include <iostream>
#include <string>
#include <cctype>    //For std::isspace
#include <fstream>   //Needed by read_sailings to work with files
#include <stdexcept> //Needed by read_sailings to handle exceptions
#include <iomanip> 
#include <set>  //Needed by print_sailing to format output
using namespace std;
/* A structure type to represent a year/month/day combination */
struct Date
{
    int day{0};
    int month{0};
    int year{0};
};

/* A structure type to represent an hour:minute pair */
struct TimeOfDay
{
    int hour{0};
    int minute{0};
};

/* A structure type to store the parameters of a particular sailing */
struct Sailing
{
    int route_number{0};
    string source_terminal{""};
    string dest_terminal{""};
    string vessel_name{""};

    Date departure_date{};
    TimeOfDay scheduled_departure_time{};

    int expected_duration{0};
    int actual_duration{0};
};

/* A structure type to store aggregated performance data for a single
   route. */
struct RouteStatistics
{
    int route_number{0};
    int total_sailings{0};
    int late_sailings{0};
};

/* A structure type to store aggregated performance data for a single
   day. */
struct DayStatistics
{
    Date date{};
    int total_sailings{0};
    int late_sailings{0};
};

/* Structure types to represent various issues that may occur during parsing */

/* Error case: Line contains too many or too few fields.
               The num_fields member will store the number of fields found. */
struct IncompleteLineException
{
    unsigned int num_fields{}; //
};

/* Error case: One (or more) fields in the line is empty (or contains only
               whitespace). The which_field member will store the index
               of the first empty field in the line. */
struct EmptyFieldException
{
    unsigned int which_field{}; //The first field is field 0, the last field is field 10
};

/* Error case: One or more numeric fields in the line contains non-numeric data.
               The bad_field member will store the text representation of the first
               field in the line with invalid non-numeric data. */
struct NonNumericDataException
{
    string bad_field{};
};

/* Error case: The departure hour/minute are valid numbers, but not a valid
               time (hour in the range 0 - 23, minute in the range 0 - 59).
               The bad_time member will store the invalid Time object. */
struct InvalidTimeException
{
    TimeOfDay bad_time{};
};

/* Function prototypes */
/* Put your implementations of these functions in a2_functions.cpp */

/* Functions to implement */

/* parse_sailing(input_line)
   Given a string containing a line from the input file, convert the
   data in the line to a Sailing instance and return the complete
   Sailing object.

   If the line cannot be parsed successfully, the function will throw
   an exception instead of returning a complete Sailing object.
   The function may not throw ANY exceptions (directly or indirectly) besides
   the ones listed below.

   Your code must check for errors in the order they are listed below.
   For example, if the line has errors in both case 1 and case 2, the
   function will throw the exception for error case 1 (and never check
   case 2).

   When an exception is thrown for a particular error, your code must
   populate the exception object with the appropriate data (see the description
   of each object above).

   Error cases:
    1. If the line contains the wrong number of fields, throw an exception
       of type IncompleteLineException. There should be 11 fields, separated by
       commas (so there should be 10 commas in a line with the correct number of
       fields).
    2. If any of the fields in the line is empty (i.e. length zero) or contains
       only whitespace, throw an exception of type EmptyFieldException. You
       can check whether a single character is whitespace using std::isspace,
       and can use std::isspace in a loop to test whether an entire string is
       whitespace.
    3. If any of the numeric fields (route number, year, month, day, hour,
       minute, expected duration, actual duration) do not begin with
       numeric data (e.g. if one of those fields contains the text "abcd"
       "a123b" or "ab123"), throw an exception of type NonNumericDataException.
       Note that a field which begins with a number and contains non-numeric
       data afterward (e.g. "123abc") is not an error (and should be parsed
       as the number 123); this is for programming convenience (since that
       case is harder to detect).
    4. If the departure time fields (hour and minute) do not comprise a valid
       24-hour time, throw an exception of type InvalidTimeException.

   If none of the above errors occurred, store the parsed data into a Sailing
   object and return that.

   Advice: Create some extra functions to help with the various subtasks
           involved in this function, rather than putting all of the code
           in one place.
*/
bool non_num(std::string const &test){
    if (('0' <= test.at(0) && test.at(0)  <= '9') || test.at(0) == '-')
        return 0;
    return 1; 
}

Sailing parse_sailing(string const &input_line){


auto length{input_line.length()};
vector<string> seperated_input {};
string hold;
//throw 1
unsigned int commas=0;
for(int i=0; i<input_line.length(); i++){
    if(input_line.at(i)==','){
        commas++;
    }
}
if(commas != 10){
    throw IncompleteLineException{commas};
}

//I want to make a sorted vector into components 
int x =0; 
//loops through input, checks for numbers and letters, and stores one entry in hold. once you hit a comma it puts hold in the sorted vector of stings and clears hold
for(int i=0; i<input_line.length(); i++){
    if(input_line.at(i) == ','){
        seperated_input.push_back(hold);
        hold.clear();
    }else if(i == input_line.length()-1){
        hold.push_back(input_line.at(i));
        seperated_input.push_back(hold);
        hold.clear();
    }
    else{
        hold.push_back(input_line.at(i));
    }
}
//so now we have a vector of seperated input
//throw 2
for(unsigned int j=0; j<seperated_input.size(); j++){
   auto character = seperated_input.at(j);
   int whitespace  {1};

    for(auto ch: character){ //checking for white space
        if(!isspace(ch)){
            whitespace = 0;
        }
    }
       if(whitespace|| character.empty()){
        throw EmptyFieldException{j};
    }
}

//throw 3
std::vector<int> numindex {0,3,4,5,6,7,9,10};
for (auto index : numindex){
    if (non_num(seperated_input.at(index)))
        throw NonNumericDataException {seperated_input.at(index)};
}

//throw 4
TimeOfDay time {};
time.hour = stoi(seperated_input.at(6));
time.minute = stoi(seperated_input.at(7));
if(time.hour > 23 || time.minute > 59 || time.hour<0 || time.minute<0){
    throw InvalidTimeException{time};
}

Date date {stoi(seperated_input.at(5)), stoi(seperated_input.at(4)), stoi(seperated_input.at(3))};

//make a sailing object called sailing, storing / organizing everything in it
Sailing sailing{};
sailing.route_number = stoi(seperated_input.at(0));
sailing.source_terminal = seperated_input.at(1);
sailing.dest_terminal = seperated_input.at(2);
sailing.departure_date = date;
sailing.scheduled_departure_time = time;
sailing.expected_duration = stoi(seperated_input.at(9));
sailing.actual_duration = stoi(seperated_input.at(10));
sailing.vessel_name = seperated_input.at(8);

return sailing;
}

/* performance_by_route(sailings)
   Given a vector of Sailing instances (in no particular order), return
   a vector of RouteStatistics instances, with exactly one entry in the result
   vector for each unique route number in the input vector.

   To be clear, there may be many sailings in the input vector with a particular
   route number (e.g. 3), but each route number must appear in only one entry
   of the result vector.

   Each RouteStatistics object will also contain the total number of sailings
   and total number of late sailings on each route.

   Recall from the specification that a "late" sailing is any sailing
   that took at least five minutes longer than expected. That is, a sailing
   where
     actual_duration >= expected_duration + 5

   Return value:
     A vector of RouteStatistics objects, in any order, where each route number
     appearing in the input vector is represented by exactly one RouteStatistics
     instance in the result.

*/
vector<RouteStatistics> performance_by_route(vector<Sailing> const &sailings)
{
    vector<RouteStatistics> performance{}; //This is the vector containing the information to be returned
    
    set<int> nums;
    for(auto sail: sailings){
        nums.insert(sail.route_number);
    }

    for(auto route_num : nums){
        RouteStatistics hold{route_num,0,0}; //hold data temporarily 
        for(auto sailing : sailings){
            if(route_num==sailing.route_number){
                hold.total_sailings++;
                if(sailing.actual_duration>=sailing.expected_duration+5){
                    hold.late_sailings++;
                }
            } 
        }
        performance.push_back(hold);
    }

    return performance;

}

/* best_days(sailings)
   Recall that a sailing is considered "late" if
    actual_duration >= expected_duration + 5

   Generally, a day with a large number of late sailings is a "bad day" for
   travellers.

   The "best days" are any days in the dataset for which the ratio
     late_sailings/total_sailings
   is the lowest (in the best possible case, there will be zero late sailings,
   and the ratio will equal zero).

   Given a vector of Sailing objects, this function returns a vector of
   DayStatistics objects for all of the "best days" in the dataset, which
   are all days in the dataset that have the lowest ratio of late sailings
   to total sailings.
   Note that there may be multiple such days.

   Return value:
     A vector of DayStatistics objects, in any order, where each element of the vector
     corresponds to a different date (meeting the criteria of "best days" above).
     If the input vector of sailings is empty, the return value will be an empty vector.
*/

bool days_equal (Date firstday, Date secondday){ // guess what it does lol
    bool matchdate {0};
    if (firstday.year == secondday.year)
        if (firstday.month == secondday.month)
            if (firstday.day == secondday.day)
                matchdate = 1;
    return matchdate;
}


vector<DayStatistics> best_days(vector<Sailing> const &sailings)
{
    vector<DayStatistics> best{};
    vector <Date> days{};
    vector<DayStatistics> all_days{};
//want to count total number of sailings
    for(auto sail: sailings){
        Date sailday {sail.departure_date};
        bool isnewday {1};
        
        for (size_t i {0}; i < days.size(); i++){
            Date checkday {days.at(i)};
            if (days_equal(checkday,sailday)){
                all_days.at(i).total_sailings ++;
                if(sail.actual_duration>=sail.expected_duration+5){
                    all_days.at(i).late_sailings++;
                }
                isnewday = 0;
            }
        }
        cout << "Here";
        if (isnewday){
                int late_temp {0};
                if(sail.actual_duration>=sail.expected_duration+5){
                    late_temp ++;
                }
                DayStatistics temp{sailday,1,late_temp};
                all_days.push_back(temp);
                days.push_back(sailday);
            }
    }

//now to find the best ones
//set inital ratio with the first numbers to compare against
int top = all_days.at(0).late_sailings; 
int bottom = all_days.at(0).total_sailings;

for(auto dayst : all_days){
    int cur_top = dayst.late_sailings;
    int cur_bottom = dayst.total_sailings;

    if(top*cur_bottom == bottom*cur_top){
        best.push_back(dayst);
    }
    else if(top*cur_bottom > bottom*cur_top){
        best.clear();
        best.push_back(dayst);
        top=cur_top;
        bottom=cur_bottom;
    }
}



    return best;
}

/* worst_days(sailings)
   See the description of best_days().

   The "worst days" are any days in the dataset for which the ratio
     late_sailings/total_sailings
   is the highest (in the worst possible case, every sailing is late,
   and the ratio will equal one).

   Given a vector of Sailing objects, this function returns a vector of
   DayStatistics objects for all of the "worst days" in the dataset,which
   are all days in the dataset that have the highest ratio of late sailings
   to total sailings.
   Note that there may be multiple such days.

   Return value:
     A vector of DayStatistics objects, in any order, where each element of the vector
     corresponds to a different date (meeting the criteria of "worst days" above).
     If the input vector of sailings is empty, the return value will be an empty vector.
*/
vector<DayStatistics> worst_days(vector<Sailing> const &sailings)
{
    vector<DayStatistics> worst{};
    vector <Date> days{};
    vector<DayStatistics> all_days{};
//want to count total number of sailings
    for(auto sail: sailings){
        Date sailday {sail.departure_date};
        bool isnewday {1};
        
        for (size_t i {0}; i < days.size(); i++){
            Date checkday {days.at(i)};
            if (days_equal(checkday,sailday)){
                all_days.at(i).total_sailings ++;
                if(sail.actual_duration>=sail.expected_duration+5){
                    all_days.at(i).late_sailings++;
                }
                isnewday = 0;
            }
            if (isnewday){
                int late_temp {0};
                if(sail.actual_duration>=sail.expected_duration+5){
                    late_temp ++;
                }
                DayStatistics temp{sailday,1,late_temp};
                all_days.push_back(temp);
                days.push_back(sailday);
            }

        }
        
    }

//now to find the best ones
//set inital ratio with the first numbers to compare against
int top = all_days.at(0).late_sailings; 
int bottom = all_days.at(0).total_sailings;

for(auto dayst : all_days){
    int cur_top = dayst.late_sailings;
    int cur_bottom = dayst.total_sailings;

    if(top*cur_bottom == bottom*cur_top){
        worst.push_back(dayst);
    }
    else if(top*cur_bottom < bottom*cur_top){
        worst.clear();
        worst.push_back(dayst);
        top=cur_top;
        bottom=cur_bottom;
    }
}
    return worst;
}


/* Provided functions (already implemented in a2_functions.cpp) */
/* You do not have to understand or modify these functions (although they
   are of the same level of difficulty as the other parts of the assignment) */
vector<Sailing> read_sailings(string const &input_filename)
{
    vector<Sailing> all_sailings;
    ifstream input_file;
    input_file.open(input_filename);

    int valid_sailings{0};
    int total_lines{0};

    if (input_file.is_open())
    {
        string line;
        while (getline(input_file, line))
        {
            total_lines++;
            try
            {
                Sailing s{parse_sailing(line)};
                valid_sailings++;
                all_sailings.push_back(s);
            }
            catch (IncompleteLineException &e)
            {
                cout << "Line " << total_lines << " is invalid: ";
                cout << e.num_fields << " fields found." << endl;
            }
            catch (EmptyFieldException &e)
            {
                cout << "Line " << total_lines << " is invalid: ";
                cout << "Field " << e.which_field << " is empty." << endl;
            }
            catch (NonNumericDataException &e)
            {
                cout << "Line " << total_lines << " is invalid: ";
                cout << "\"" << e.bad_field << "\" is non-numeric." << endl;
            }
            catch (InvalidTimeException &e)
            {
                cout << "Line " << total_lines << " is invalid: ";
                cout << e.bad_time.hour << ":" << e.bad_time.minute << " is not a valid time." << endl;
            }
        }
        input_file.close();
    }
    else
    {
        throw runtime_error("Unable to open input file");
    }
    int invalid_sailings{total_lines - valid_sailings};
    cout << "Read " << valid_sailings << " records." << endl;
    cout << "Skipped " << invalid_sailings << " invalid records." << endl;
    return all_sailings;
}

void print_sailing(Sailing const &sailing)
{
    cout << "Route " << sailing.route_number;
    cout << " (" << sailing.source_terminal << " -> " << sailing.dest_terminal << "): ";
    cout << sailing.departure_date.year << "-";
    cout << setfill('0') << setw(2) << sailing.departure_date.month << "-";
    cout << setfill('0') << setw(2) << sailing.departure_date.day << " ";
    cout << setfill('0') << setw(2) << sailing.scheduled_departure_time.hour << ":";
    cout << setfill('0') << setw(2) << sailing.scheduled_departure_time.minute << " ";
    cout << "[Vessel: " << sailing.vessel_name << "] ";
    cout << sailing.actual_duration << " minutes (" << sailing.expected_duration << " expected)" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cout << "Usage: ./assignment_2 action input_filename" << endl;
        cout << "       where action is either 'route_summary' or 'days'" << endl;
        return 1;
    }

    string action{argv[1]};
    string input_filename{argv[2]};

    auto all_sailings{read_sailings(input_filename)};

    if (action == "route_summary")
    {
        cout << "Performance by route:" << endl;
        auto statistics{performance_by_route(all_sailings)};
        for (auto stats : statistics)
        {
            cout << "Route " << stats.route_number << ": " << stats.total_sailings << " sailings (" << stats.late_sailings << " late)" << endl;
        }
    }
    else if (action == "days")
    {
        auto best{best_days(all_sailings)};
        auto worst{worst_days(all_sailings)};
        cout << "Best days:" << endl;
        for (auto stats : best)
        {
            cout << stats.date.year << "-" << stats.date.month << "-" << stats.date.day << ": ";
            cout << stats.total_sailings << " sailings (" << stats.late_sailings << " late)" << endl;
        }
        cout << "Worst days:" << endl;
        for (auto stats : worst)
        {
            cout << stats.date.year << "-" << stats.date.month << "-" << stats.date.day << ": ";
            cout << stats.total_sailings << " sailings (" << stats.late_sailings << " late)" << endl;
        }
    }
    else
    {
        cout << "Invalid action " << action <<endl;
    }

    return 0;
}