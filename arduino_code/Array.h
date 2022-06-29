template<typename T> class Array{
    private:
        int len = 0;
        int fullLen = 0;
        T* data = nullptr;
    public:

        int fullSize() const {
            return fullLen;
        }
        Array(){}
        int size() const {
            return len;
        }

        // int operator[](string str) const{
        //     for(int i = 0; i < size(); i++){
        //         if(data[i] == str){
        //             return i;
        //         }
        //     }
        //     return -1;
        // }

        T operator[](int i) const{
            return data[i];
        }

        T & operator[](int idx){
            // if(idx >= size()){
            //     T* newData = new T[idx+1];
            //     for(int i = 0; i < size(); i++){
            //         newData[i] = data[i];
            //     }
            //     delete[] data;
            //     data = newData;
            //     len = idx+1;
            // }
            return data[idx];
        }

        T get(int idx){
            return data[idx];
        }

        void push_back(T value){
            if(fullLen <= len){
                fullLen += floor(log2(fullLen+2));
                T* newData = new T[fullLen];
                for(int i = 0; i < len; i++){
                    newData[i] = data[i];
                }
                if(data != nullptr) delete[] data;
                data = newData;
            }
            data[len] = value;
            len++;
        }

        void pop(){
            if(len > 0){
                len--;
                fullLen = len;
                T* newData = new T[len];
                for(int i = 0; i < len; i++){
                    newData[i] = data[i];
                }
                delete data;
                data = newData;
            }
        }
        
        ~Array(){
            delete[] data;
        }
};