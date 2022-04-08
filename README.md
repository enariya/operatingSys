Topic: Producer-Consumer Problem

The producer generates items and puts items onto the table. The consumer will pick up items. The table can only hold two items at the same time. When the table is complete, the producer will wait. When there are no items, the consumer will wait. We use semaphores to synchronize producer and consumer.  Mutual exclusion should be considered. We use threads in the producer program and consumer program. Shared memory is used for the “table”.

Compile instruction:
> gcc producer.c -pthread -lrt -o producer
> 
> gcc consumer.c -pthread -lrt -o consumer
> 
> ./producer & ./consumer
> 

Example 1:

enariya@enariya-VirtualBox:~/project/operatingSys$ ./producer & ./consumer

[1] 13087

Producer is producing.

id 0: filling with item: 32

Consumer is consuming.

Empty table, next attempt will happem in next critical section

Consumer is consuming.

Empty table, next attempt will happem in next critical section

Producer is producing.

id 1: filling with item: 35

Consumer is consuming.

id 1: filled with item: 35. clearing in progress

Producer is producing.

id 0: filled, recheck happens in next critical section

Consumer is consuming.

id 0: filled with item: 32. clearing in progress

Producer is producing.

id 0: filling with item: 508

Consumer is consuming.

Empty table, next attempt will happem in next critical section

Producer is producing.

id 1: filling with item: 745

Consumer is consuming.

id 1: filled with item: 745. clearing in progress

Producer is producing.

id 0: filled, recheck happens in next critical section

Consumer is consuming.

id 0: filled with item: 508. clearing in progress

Producer is producing.

id 0: filling with item: 282

Consumer is consuming.

Empty table, next attempt will happem in next critical section

Producer is producing.

id 1: filling with item: 501

Consumer is consuming.

id 1: filled with item: 501. clearing in progress

Producer is producing.

id 0: filled, recheck happens in next critical section

Consumer is consuming.

id 0: filled with item: 282. clearing in progress

Producer is producing.

id 0: filling with item: 531

Consumer is consuming.

Empty table, next attempt will happem in next critical section

Producer is producing.

<img width="630" alt="Screen Shot 2022-04-08 at 10 04 20 AM" src="https://user-images.githubusercontent.com/60280129/162452308-ad482721-4420-4407-a5a3-bb7c59519280.png">
<img width="521" alt="Screen Shot 2022-04-08 at 10 04 35 AM" src="https://user-images.githubusercontent.com/60280129/162452431-ba7ab81c-7b4c-4567-ba57-5ec560c69639.png">




