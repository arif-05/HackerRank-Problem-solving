#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int>& count, int d) {
    vector<int> prefix_sum(201);
   
    prefix_sum[0] = count[0];
    for (int i = 1; i < 201; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + count[i];
    }

    int median_pos1 = (d + 1) / 2;  
    int median_pos2 = (d % 2 == 0) ? median_pos1 + 1 : median_pos1;   
    int m1 = 0, m2 = 0;
    for (int i = 0; i < 201; i++) {
        if (m1 == 0 && prefix_sum[i] >= median_pos1) {
            m1 = i;
        }
        if (prefix_sum[i] >= median_pos2) {
            m2 = i;
            break;
        }
    }

    return (m1 + m2) / 2.0;
}

int activityNotifications(vector<int>& expenditure, int d) {
    vector<int> count(201, 0); 
    int notifications = 0;

 
    for (int i = 0; i < d; i++) {
        count[expenditure[i]]++;
    }

  
    for (int i = d; i < expenditure.size(); i++) {
        double median = findMedian(count, d);  

        if (expenditure[i] >= 2 * median) {
            notifications++;  
        }

       
        count[expenditure[i - d]]--;  
        count[expenditure[i]]++;      
    }

    return notifications;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for (int i = 0; i < n; i++) {
        cin >> expenditure[i];
    }

    int result = activityNotifications(expenditure, d);
    cout << result << endl;

    return 0;
}
