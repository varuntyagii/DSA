class ProductOfNumbers {
public:
vector<int>ans;
int n;
    ProductOfNumbers() {
        // ans.clear();
        // n = 0;
         ans.push_back('[]');
    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        int p = 1;
        int m = ans.size();
        for(int i = m - k; i < m; i++){
            p *= ans[i];
        }
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */