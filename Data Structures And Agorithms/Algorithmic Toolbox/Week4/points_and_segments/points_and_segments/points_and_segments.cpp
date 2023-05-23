#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector;
using namespace std;

vector<int> fast_count_segments(/*vector<int> starts, vector<int> ends*/vector<std::pair<int, int>>& ranges, vector<int> points) {
    vector<int> cnt(points.size());
    //write your code here
	vector<pair<int, int>> vec;
	unordered_map<int, int> point_to_counts;

	vec.reserve(ranges.size() * 2 + points.size());
	point_to_counts.reserve(points.size());

	for (auto&& i : ranges) {
		vec.push_back(make_pair(i.first, 0));
		vec.push_back(make_pair(i.second, 2));
	}
	for (auto&& i : points) { vec.push_back(make_pair(i, 1)); }

	sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
		if (a.first == b.first) return a.second < b.second;
		else
			return a.first < b.first;
		});
	int count = 0;
	for (auto&& i : vec) {
		if (i.second == 0) {
			count++;
		}
		else if (i.second == 2) {
			count--;
		}
		else {
			point_to_counts.insert(make_pair(i.first, count));
		}
	}
	for (int i = 0; i < points.size(); i++) {
		cnt[i] = point_to_counts[points[i]];
	}
	return cnt;
    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;
    /*vector<int> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        std::cin >> starts[i] >> ends[i];
    }*/
	vector<std::pair<int, int>> ranges;
	ranges.reserve(n);
	int start, end;
	for (size_t i = 0; i < n; i++) {
		std::cin >> start >> end;
		if (start <= end) ranges.push_back(make_pair(start, end));
	}

    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        std::cin >> points[i];
    }
    //use fast_count_segments

    /*vector<int> cnt = naive_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        std::cout << cnt[i] << ' ';
    }*/
	auto cnt1 = fast_count_segments(ranges, points);
	for (size_t i = 0; i < cnt1.size(); i++) {
		cout << cnt1[i] << ' ';
	}
}
