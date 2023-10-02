#include<iostream>
#include<vector>

using namespace std;

typedef struct ACTIVITY
{
    int process_id;
    int start_time;
    int finish_time;
} Activity;

bool cmp_finish_time(Activity, Activity);
void greedy_activity_selection_problem(Activity*, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Activity activities[] = {
        {1, 1, 3},
        {2, 1, 5},
        {3, 3, 6},
        {4, 3, 7},
        {5, 7, 8},
        {6, 6, 9}
    };

    int n = sizeof(activities) / sizeof(activities[0]);

    cout << "Selected activities : ";
    greedy_activity_selection_problem(activities, n);

    return 0;
}

bool cmp_finish_time(Activity a, Activity b)
{
    return (a.finish_time < b.finish_time);
}

void greedy_activity_selection_problem(Activity *activities, int n)
{
    int i = 0;
    cout << "P" << activities[i].process_id << " ";
    for(int j = 1; j < n; ++j)
    {
        if(activities[j].start_time >= activities[i].finish_time)
        {
            cout << "P" << activities[j].process_id << " ";
            i = j;
        }
    }

    cout << "\n";
}