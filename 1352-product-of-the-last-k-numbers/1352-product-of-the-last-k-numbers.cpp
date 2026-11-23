class ProductOfNumbers {
public:
    vector<int>a;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        a.push_back(num);
    }
    
    int getProduct(int k) {
        int n=a.size(),b=1;
        
        for(int x=n-k;x<n;x++){
             if(a[x]==0){
                return 0;
             }
             b*=a[x];
        }
         return b;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */