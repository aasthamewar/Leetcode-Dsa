class RideSharingSystem {
public:
    queue<int> driver;
    vector<int> rider;
    map<int,int> mp;
    int start=0;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        mp[riderId]=rider.size();
        rider.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(start < rider.size() && rider[start]==-1){
            start++;}
            if(driver.empty() || start==rider.size())return {-1,-1};
            int dId=driver.front();
            driver.pop();
            int rId=rider[start];
            start++;
            mp.erase(rId);
            return {dId,rId};

        
    }
    
    void cancelRider(int riderId) {
     if(mp.count(riderId)){
        int idx=mp[riderId];
        rider[idx]=-1;
        mp.erase(riderId);
     }   
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */