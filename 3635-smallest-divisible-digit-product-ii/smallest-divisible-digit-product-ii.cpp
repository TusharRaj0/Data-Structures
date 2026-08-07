class Solution {
public:
    using ll = long long;

    string buildSuffix(ll need, int slots) {
        string suffix;

        for (int d = 9; d >= 2; d--) {
            while (need % d == 0) {
                suffix.push_back(d + '0');
                need /= d;
            }
        }

        while (suffix.size() < slots)
            suffix.push_back('1');

        reverse(suffix.begin(), suffix.end());

        return suffix;
    }

    string smallestNumber(string num, long long t) {
        int n = num.size();

        ll temp = t;
        for (int p : {2, 3, 5, 7}) {
            while (temp % p == 0)
                temp /= p;
        }

        if (temp != 1)
            return "-1";

        vector<ll> remain(n + 1, t);

        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';

            if (digit == 0)
                break;

            remain[i + 1] = remain[i] / gcd(remain[i], (ll)digit);
        }

        if (remain[n] == 1)
            return num;

        int limit = n - 1;
        int zeroPos = num.find('0');

        if (zeroPos != -1)
            limit = zeroPos;

        for (int i = limit; i >= 0; i--) {

            ll need = remain[i];
            int freeSlots = n - i - 1;

            for (int d = (num[i] - '0') + 1; d <= 9; d++) {

                ll newNeed = need / gcd(need, (ll)d);

                string suffix = buildSuffix(newNeed, freeSlots);

                if (suffix.size() == freeSlots) {
                    return num.substr(0, i) + char(d + '0') + suffix;
                }
            }
        }

        return buildSuffix(t, n + 1);
    }
};