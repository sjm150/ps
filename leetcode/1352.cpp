class ProductOfNumbers {
    vector<int> p;
public:
    void add(int num) {
        if (num) p.push_back(num * (p.empty() ? 1 : p.back()));
        else p.resize(0);
    }
    
    int getProduct(int k) {
        if (k > p.size()) return 0;
        int i = p.size() - k - 1;
        return p.back() / (i < 0 ? 1 : p[i]);
    }
};