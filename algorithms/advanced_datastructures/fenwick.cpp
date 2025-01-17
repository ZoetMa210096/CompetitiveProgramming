using namespace std;
using ll = long long;

constexpr ll N = 100001;
ll fen[N] = {0};

void update(int idx, ll val) {
    while(idx < N) {
        fen[idx]+=val;
        idx+=idx&(~idx+1);
    }
}

ll query(int idx) {
    ll s = 0;
    while(idx) {
        s+=fen[idx];
        idx&=idx-1;
    }
    return s;
} 

ll rangeQuery(int l, int r) {
    return query(r) - query(l-1);
}
