#include <cinttypes>
 
#define RING_BUFFER_SIZE 1000
class ring_buffer_queue
{
    private :
        int64_t write = 0;
        int64_t read = 0;
        int64_t size = RING_BUFFER_SIZE;
        int64_t buffer[RING_BUFFER_SIZE];
    public :
  
    void push(int64_t val)
    {
        buffer[write%size] = val;
        write++;
    }
  
    int64_t pop()
    {
        int64_t ret = buffer[read%size];
        read++; 
        return ret;
    }
};
