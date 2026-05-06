/*
Circular Buffer:
* fixed size buffer
* write pointer at head
* read pointer at tail
Key Difference from queue:
* 2 Operational modes
    -> Overwrite mode: new data overwrites old data (circular buffer)
    -> Reject mode: new data is dropped if buffer is full (circular queue)
    ----------------------------------------------------------------------------------
           Circular Queue           |       Circular buffer
    ----------------------------------------------------------------------------------
    * Never overwrites data         | * Overwrites old data when full
    * Rejects new data if full      | * Always accepts new data; no drop
    * strict FIFO behavior          | * Used in sensor streams, logs, audio buffers
    * Used when data must not be    | * Highly used in firmware designs
    lost or order matters strictly  |
    -----------------------------------------------------------------------------------

“A queue preserves all data and rejects new elements when full,
while a circular buffer can overwrite old data, making it suitable for continuous data streams.”

* Key Idea using Overwrite mode/ real circular buffer:
-> When buffer is full and we write new data, we advance tail automatically.
-> Step-by-step
Suppose:
SIZE = 5
Fill buffer:
head = 0 → 1 → 2 → 3 → 4 → 0 (wrap)
tail = 0

Now: head == tail → FULL
    Now new data comes, We overwrite
What happens?
buffer[head] = new_data;
head = (head + 1) % SIZE;
tail = (tail + 1) % SIZE;   // ← IMPORTANT
* Why move tail?
Because:oldest data is lost, so tail must move forward
Visual Before:
[A B C D E]
 ↑       ↑
tail    head

Write F:
[F B C D E]
   ↑     ↑
 tail   head

Key rule: In overwrite mode:
“If writing makes head catch tail → move tail forward”

* “How are we reaching full condition?” We dont block at full, we instead
detect collisio head == tail and handle it by mvoing tail

*“In overwrite-mode circular buffers, when the write pointer catches the read pointer,
I advance the read pointer to discard the oldest data.”
*/

#define N 5
int buffer[N];
int head = 0, tail = 0;

void write_to_buffer(int data)
{
    buffer[head] = data;

    head = (head + 1) % N;

    if (head == tail) // buffer is full, move tail
    {
        tail = (tail + 1) % N;
    }
}

int read_from_buffer(void)
{
    if (head == tail)
    {
        printf("Empty buffer\n");
        return -1;
    }

    int data = buffer[tail];
    tail = (tail + 1) % N;
    return data;
}
/*
Final Intuition:
Queue: “Don’t lose data”
Circular buffer: “Always accept new data, even if old is lost”
*/