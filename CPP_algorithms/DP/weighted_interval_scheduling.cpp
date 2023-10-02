#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct JOB
{
    int process_id;
    int start_time;
    int finish_time;
    int value;
} Job;

bool cmp_finish_time(Job, Job);
int recursive_WIS(Job*, int);
int latest_non_conflict(Job*, int);
int dp_WIS(vector<int>&, Job*, int);
void WIS_with_tabulation(vector<int>&, vector<int>&, Job*, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Job jobs[] = {
        {1, 1, 3, 1},
        {2, 1, 5, 3},
        {3, 3, 6, 3},
        {4, 3, 7, 4},
        {5, 7, 8, 1},
        {6, 6, 9, 3}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    sort(jobs, jobs + n, cmp_finish_time);
    cout << "Recursive approach : " << recursive_WIS(jobs, n) << "\n";

    vector<int> dp_table(n, 0);
    dp_table[0] = jobs[0].value;
    cout << "Dynamic programming approach : " << dp_WIS(dp_table, jobs, n) << "\n";

    vector<int> order;
    cout << "Sequence of jobs : ";
    WIS_with_tabulation(order, dp_table, jobs, n - 1);
    for(int i = order.size() - 1; i >= 0; --i)
        cout << "P" << order[i] << " ";
    cout << "\n";

    return 0;
}

bool cmp_finish_time(Job a, Job b)
{
    return (a.finish_time < b.finish_time);
}

int recursive_WIS(Job *jobs, int n)
{
    if(n == 1)
        return jobs[n - 1].value;
    
    int value_in_schedule = jobs[n - 1].value;
    int index = latest_non_conflict(jobs, n - 1);
    if(index != -1)
        value_in_schedule += recursive_WIS(jobs, index + 1);
    
    return max(value_in_schedule, recursive_WIS(jobs, n - 1));
}

int latest_non_conflict(Job *jobs, int index)
{
    for(int i = index - 1; i >= 0; --i)
        if(jobs[i].finish_time <= jobs[index].start_time)
            return i;

    return -1;
}

int dp_WIS(vector<int> &dp, Job* jobs, int n)
{
    for(int i = 1; i < n; ++i)
    {
        int value_in_schedule = jobs[i].value;
        int index = latest_non_conflict(jobs, i);
        if(index != -1)
            value_in_schedule += dp[index];
        
        dp[i] = max(value_in_schedule, dp[i - 1]);
    }

    return dp[n - 1];
}

void WIS_with_tabulation(vector<int> &order, vector<int> &dp, Job* jobs, int n)
{
    if(n == 0)
    {
        order.push_back(jobs[n].process_id);
        return;
    }
    
    int index = latest_non_conflict(jobs, n);
    if(index != -1)
    {
        if(jobs[n].value + dp[index] > dp[n - 1])
        {
            order.push_back(jobs[n].process_id);
            WIS_with_tabulation(order, dp, jobs, index);
        }
    }
    else
        WIS_with_tabulation(order, dp, jobs, n - 1);
}