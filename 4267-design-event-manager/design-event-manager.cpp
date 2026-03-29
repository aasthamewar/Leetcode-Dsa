class EventManager {
public:
    unordered_map<int,int>mp; //eventid->priority
    set<pair<int,int>>st;

    EventManager(vector<vector<int>>& events) {
        for(auto& e:events){
            int id=e[0];
            int pr=e[1];

            mp[id]=pr;
            st.insert({-pr,id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(mp.find(eventId)==mp.end())return;

        int oldpriority = mp[eventId];
        //remove old pair
        st.erase({-oldpriority,eventId});
        st.insert({-newPriority,eventId});
        //update map
        mp[eventId]=newPriority;
    }
    
    int pollHighest() {
        if(st.empty())return -1;
        int eventId=st.begin()->second;

        st.erase(st.begin());
        mp.erase(eventId);

        return eventId;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */