#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

class Num {
private:
    int base;
    void ToDemicalInt(Num &s) {
        s.setNumber("0", 10);
        Num a;
        a.setNumber(std::to_string(base), 10);
        for (int i = (*this).num.size() - 1; i >= 0; --i) {
            Num b;
            b.setNumber(std::to_string((*this).num[i]), 10);
            s = s + (b * (a ^ ((*this).num.size() - i - 1)));
        }
        s.base = 10;
    }
    int ToInt(Num a) {
        int b = 0;
        for (int i = a.num.size() - 1; i >= 0; --i) {
            b += (a.num[i] * pow(10, (a.num.size() - 1 - i)));
        }
        return b;
    }

public:
    std::vector<int> num, period, pred;
    void setNumber(std::string s, int in) {
        std::vector<unsigned> a;
        base = in;
        bool isFr = 0, isInPeriod = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '.') {
                isFr = 1;
                continue;
            }
            if (s[i] == '(') {
                isInPeriod = 1;
                isFr = 0;
                continue;
            }
            if (s[i] == ')') {
                break;
            }
            if (isFr) {
                if (s[i] > '9') {
                    pred.push_back(s[i] - 'A' + 10);
                }
                else {
                    pred.push_back(s[i] - '0');
                }
            }
            else if (isInPeriod) {
                if (s[i] > '9') {
                    period.push_back(s[i] - 'A' + 10);
                }
                else {
                    period.push_back(s[i] - '0');
                }
            }
            else {
                if (s[i] > '9') {
                    num.push_back(s[i] - 'A' + 10);
                }
                else {
                    num.push_back(s[i] - '0');
                }
            }
        }
    }
    void convert_to(int to) {
        int from = base;
        Num s;
        s.base = base;
        Num a = *this;
        int to_ = to;
        while (to_ / from > 0) {
            s.num.insert(s.num.begin(), to_%from);
            to_ /= from;
        }
        s.num.insert(s.num.begin(), to_%from);

        Num result;
        result.setNumber("", to);
        Num null;
        null.num = { 0 };
        while (!(null >= a / s)) {
            Num inn = a % s;
            Num aa;
            inn.ToDemicalInt(aa);
            int in = ToInt(aa);
            result.num.insert(result.num.begin(), in);
            a = a / s;
        }
        Num inn = a % s;
        Num aa;
        inn.ToDemicalInt(aa);
        int in = ToInt(aa);
        result.num.insert(result.num.begin(), in);
        *this = result;
    }
    void toDecimal() {
        if (base == 10) {
            return;
        }
        Num s;
        ToDemicalInt(s);

        Num up, down, tmp, t;
        up.setNumber("", base);
        tmp.setNumber("", base);
        t.setNumber("", base);
        down.setNumber("", 10);
        up.num = pred;
        if (period.size() == 0) {
            up.num.push_back(0);
        }
        else {
            for (int &i : period) {
                up.num.push_back(i);
            }
        }
        tmp.num = pred;
        Num bs;
        bs.base = 10;
        bs.setNumber(std::to_string(base), 10);
        down = ((bs ^ ((int)up.num.size())) - (bs ^ ((int)tmp.num.size())));
        up.ToDemicalInt(t);
        up = t;

        t.num = {};
        tmp.ToDemicalInt(t);
        tmp = t;

        up = up - tmp;

        Num de, nu;
        de.setNumber("10", 10);
        nu.setNumber("0", 10);
        std::vector<Num> was;
        int cn = 0;
        while (1) {


            up = up * de;


            auto x = std::find(was.begin(), was.end(), up);
            if (x != was.end()) {
                for (int i = 0; i < was.size(); ++i) {
                    if (was[i] == *x) {
                        for (int j = i; j < was.size(); j++) {
                            s.period.push_back(s.pred[i]);
                            s.pred.erase(s.pred.begin() + i);
                        }
                        break;
                    }

                }
                break;
            }
            s.pred.push_back(ToInt(up / down));
            was.push_back(up);
            if (up >= down) {
                up = up % down;
            }
            if (up.num == nu.num) {
                break;
            }

        }

        *this = s;
    }

    void toNumeralSystem(int to) {

        Num s = *this;
        s.convert_to(to);

        Num up, down, tmp;
        up.setNumber("", base);
        tmp.setNumber("", base);
        down.setNumber("", base);
        up.num = pred;
        if (period.size() == 0) {
            up.num.push_back(0);
        }
        else {
            for (int &i : period) {
                up.num.push_back(i);
            }
        }
        tmp.num = pred;
        Num bs; // основание базовой в целевой сс
        bs.setNumber(std::to_string(base), 10);
        bs.convert_to(to);

        down = ((bs ^ ((int)up.num.size())) - (bs ^ ((int)tmp.num.size())));
        up = up - tmp;
        up.convert_to(to);

        Num de, nu;
        de.setNumber(std::to_string(10), to);
        nu.setNumber("0", to);
        std::vector<Num> was;
        int cn = 0;
        while (1) {

            up = up * de;

            auto x = find(was.begin(), was.end(), up);
            if (x != was.end()) {
                for (int i = 0; i < was.size(); ++i) {
                    if (was[i] == *x) {
                        for (int j = i; j < was.size(); j++) {
                            s.period.push_back(s.pred[i]);
                            s.pred.erase(s.pred.begin() + i);
                        }
                        break;
                    }

                }
                break;
            }
            Num oo = up / down;
            oo.convert_to(10);
            s.pred.push_back(ToInt(oo));
            was.push_back(up);
            if (up >= down) {
                up = up % down;
            }
            if (up.num == nu.num) {
                break;
            }

        }

        *this = s;
    }

    Num operator - (Num b) {
        Num a = *this;
        int bs = a.base;
        for (int i = 0; i < fmax(a.num.size(), b.num.size()); ++i) {
            if (i >= a.num.size()) {
                a.num.insert(a.num.begin(), 0);
            }
            if (i >= b.num.size()) {
                b.num.insert(b.num.begin(), 0);
            }
        }
        int sz = a.num.size() - 1;
        for (int i = sz; i >= 0; --i) {
            if (a.num[i] < b.num[i]) {
                a.num[i] += bs;
                int cnt = i - 1;
                while (a.num[cnt] == 0) {
                    a.num[cnt] = bs - 1;
                    cnt--;
                }
                a.num[cnt] --;
            }
            a.num[i] -= b.num[i];
        }
        bool isnn = 0;
        Num c;
        c.setNumber("", bs);
        for (int i = 0; i < a.num.size(); ++i) {
            if (a.num[i] != 0) {
                isnn = 1;
            }
            if (!isnn) {
                continue;
            }
            c.num.push_back(a.num[i]);
        }
        return c;
    }
    Num operator ^ (int b) {
        Num c = *this;
        Num ci = *this;
        for (int i = 1; i < b; ++i) {
            c = c * ci;
        }
        if (b == 0) {
            c.num = { 1 };
        }
        return c;
    }
    bool operator==(const Num& rhs) const { return this->num == rhs.num; }
    Num operator + (Num a) {
        Num b = *this;
        int bs = a.base;
        for (int i = 0; i < fmax(a.num.size(), b.num.size()); ++i) {
            if (i >= a.num.size()) {
                a.num.insert(a.num.begin(), 0);
            }
            if (i >= b.num.size()) {
                b.num.insert(b.num.begin(), 0);
            }
        }
        int sz = a.num.size() - 1;
        for (int i = sz; i >= 0; --i) {
            a.num[i] += b.num[i];
            if (a.num[i] > bs-1) {
                if (i == 0) {
                    a.num.insert(a.num.begin(), 0);
                    a.num[0]++;
                    a.num[1] -= bs;
                }
                else {
                    a.num[i - 1]++;
                    a.num[i] -= bs;
                }

            }
        }
        for (int i = 0; i < fmax(a.pred.size(), b.pred.size()); ++i) {
            if (i >= a.pred.size()) {
                a.pred.push_back(0);
            }
            if (i >= b.pred.size()) {
                b.pred.push_back(0);
            }
        }
        sz = a.pred.size() - 1;
        for (int i = sz; i >= 0; --i) {
            a.pred[i] += b.pred[i];
            if (a.pred[i] > bs-1) {
                if (i == 0) {
                    bool isIn = 0;
                    for (int i = a.num.size() - 1; i >= 0; --i) {
                        if(a.num[i] != bs -1) {
                            a.num[i]++;
                            isIn = 1;
                            break;
                        }
                        else {
                            a.num[i] = 0;
                        }
                    }
                    if (!isIn) {
                        a.num.insert(a.num.begin(), 1);
                    }
                    a.pred[0] -= bs;
                }
                else {
                    a.pred[i - 1]++;
                    a.pred[i] -= bs;
                }

            }
        }
        return a;
    }
    Num operator * (Num b) {
        Num a = *this;
        int bs = a.base;
        if (a.num.size() > b.num.size()) {
            auto i = a.num;
            a.num = b.num;
            b.num = i;
        }
        int nulls = 0;
        for (int i = a.num.size() - 1; i >= 0; --i) {
            if (a.num[i] == 0) {
                nulls++;
                a.num.erase(a.num.begin() + i);
            }
            else {
                break;
            }
        }
        for (int i = b.num.size() - 1; i >= 0; --i) {
            if (b.num[i] == 0) {
                nulls++;
                b.num.erase(b.num.begin() + i);
            }
            else {
                break;
            }
        }
        Num c;
        c.setNumber("", base);
        c.num = { 0 };
        for (int i = a.num.size() - 1; i >= 0; --i) {
            Num x;
            x.setNumber("", base);
            int ws = 0;
            for (int j = b.num.size() - 1; j >= 0; --j) {
                x.num.insert(x.num.begin(), (a.num[i] * b.num[j] + ws) % bs);
                ws = (a.num[i] * b.num[j] + ws) / bs;
            }
            for (int j = 0; j < (a.num.size() - i - 1); ++j) {
                x.num.push_back(0);
            }
            if (ws > 0) {
                x.num.insert(x.num.begin(), ws);
            }
            c = c + x;
        }
        for (int i = 0; i < nulls; ++i) {
            c.num.push_back(0);
        }
        for (int i = 0; i < c.num.size(); ++i) {
            if (c.num[i] != 0) {
                break;
            }
            else {
                c.num.erase(c.num.begin() + i);
            }
        }
        if (c.num.size() == 0) {
            c.num = { 0 };
        }
        return c;
    }
    bool operator >=(Num b) {
        Num a = *this;
        while (a.num.size() > 0) {
            if (a.num[0] != 0) {
                break;
            }
            a.num.erase(a.num.begin());
        }
        if (a.num.size() == 0) {
            a.num = { 0 };
        }
        while (b.num.size() > 0) {
            if (b.num[0] != 0) {
                break;
            }
            b.num.erase(b.num.begin());
        }
        if (b.num.size() == 0) {
            b.num = { 0 };
        }

        if (a.num.size() > b.num.size()) {
            return 1;
        }
        else if (a.num.size() < b.num.size()) {
            return 0;
        }
        else {
            int i = 0;
            while (i < a.num.size()) {
                if (a.num[i] > b.num[i]) {
                    return 1;
                }
                if (a.num[i] < b.num[i]) {
                    return 0;
                }
                i++;
            }
            return 1;
        }
        return 0;
    }
    Num operator / (Num b) {
        Num a = *this;
        int ii = a.num.size() - 1, jj = b.num.size() - 1;
        int bs = a.base;

        int cnt = 0;
        Num ans;
        Num c;
        Num null;
        null.setNumber("0", bs);
        c.setNumber("", bs);
        ans.setNumber("", bs);
        /*
        if (!(a >= b)) {
            ans.num = { 0 };
            c = a;
            int cnt = 0;
            while (1) {
                cnt++;
                if (c.num == null.num || c.num.size() == 0 || cnt > 100) {
                    return ans;
                }
                bool ik = 0;
                while (!(c >= b)) {
                    if (ik) {
                        ans.pred.push_back(0);
                    }
                    c.num.push_back(0);
                    ik = 1;
                }
                int l = 1, r = bs;
                while (l < r - 1) {
                    int mid = (l + r) / 2;
                    Num d;
                    d.setNumber("", bs);
                    d.num = { mid };
                    d = d * b;
                    if (!(c >= d)) {
                        r = mid;
                    }
                    else {
                        l = mid;
                    }
                }
                ans.pred.push_back(l);
                Num d;
                d.setNumber("", bs);
                d.num = { l };
                d = d * b;
                c = c - d;
            }
            return ans;
        }*/
        while (1) {
            bool ik = 0;

            while (!(c >= b)) {
                if (ans.num.size() != 0 && ik) {
                    ans.num.push_back(0);
                }
                if (cnt >= a.num.size()) {
                    return ans;
                }
                c.num.push_back(a.num[cnt]);
                cnt++;
                ik = 1;
            }
            int l = 1, r = bs;
            while (l < r - 1) {
                int mid = (l + r) / 2;
                Num d;
                d.setNumber("", bs);
                d.num = { mid };
                d = d * b;
                if (!(c >= d)) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            ans.num.push_back(l);
            Num d;
            d.setNumber("", bs);
            d.num = { l };
            d = d * b;
            c = c - d;

        }
    }
    Num operator % (Num b) {
        Num a = *this;
        Num ret = a - (a / b)*b;
        if (ret.num.size() == 0) {
            ret.num = { 0 };
        }
        return ret;
    }
};
