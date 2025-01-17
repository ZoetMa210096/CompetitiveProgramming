using namespace std;
using ll = long long;

ll a[100001], seg[4 * 100001], lazy[4 * 100001]={0};

void build(int idx, int low, int high) {
    if(low==high) {
        seg[idx]=a[high];
        return;
    }
    int mid = (low+high)/2;
    build(idx*2+1, low, mid);
    build(idx*2+2, mid+1, high);
    seg[idx]=seg[idx*2+1]+seg[idx*2+2]; 
}

ll query(int idx, int low, int high, int ql, int qr) {
    if(low>=ql && high<=qr) return seg[idx];
    else if(high<ql || low>qr) return 0; 

    int mid = (low+high)/2;
    return query(idx*2+1, low, mid, ql, qr) + 
           query(idx*2+2, mid+1, high, ql, qr);
}

void update(int idx, int low, int high, int uidx, int uval) {
    if(low==high) {
        seg[idx]=uval;
        return;
    }
    int mid = (low+high)/2;
    if(uidx<=mid) update(idx*2+1, low, mid, uidx, uval);
    else update(idx*2+2, mid+1, high, uidx, uval);
    seg[idx]=seg[idx*2+1]+seg[idx*2+2];
}

void rangeUpdate(int idx, int low, int high, int ul, int ur, int uval) {
    if(lazy[idx]) {
        seg[idx] += lazy[idx]*(high-low+1);
        if(low!=high) {
            lazy[idx*2+1] += lazy[idx];
            lazy[idx*2+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if(high<ul || low>ur) return;
    if(low>=ul && high<=ur) {
        seg[idx] += uval*(high-low+1);
        if(low!=high) {
            lazy[idx*2+1] += uval;
            lazy[idx*2+2] += uval;
        }
        return;
    }

    int mid = (low+high)/2;
    rangeUpdate(idx*2+1, low, mid, ul, ur, uval);
    rangeUpdate(idx*2+2, mid+1, high, ul, ur, uval);
    seg[idx] = seg[idx*2+1] + seg[idx*2+2];
}

ll lazyQuery(int idx, int low, int high, int ql, int qr) {

    if(lazy[idx]!=0) {
        seg[idx] += lazy[idx]*(high-low+1);
        if(low!=high) {
            lazy[idx*2+1] += lazy[idx];
            lazy[idx*2+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if(low>=ql && high<=qr) return seg[idx];
    else if(high<ql || low>qr) return 0; 

    int mid = (low+high)/2;
    return lazyQuery(idx*2+1, low, mid, ql, qr) + 
           lazyQuery(idx*2+2, mid+1, high, ql, qr);
}
