# Monitoring in Linux
*Don't get confused with the depugging and the observability *
*Observability :* 
- Steps:
    1. Asking Questions 
        - what's going on on the last operation ? : Using **LOGS**
            - ALl the system store it's logs in file called:
                - **syslog** But it may vary from app to another cuz The Devoloper can change the location of his logs 
                - **Kernlog** it used to see the logs of the kernel
                - **dmesg**  

        - How much ?: **Metrics**
        - What are the sequences ? : **Trace** the order of set of operations
        - What are th efiles that the process use? : Through **Files and interactions** 
        
    2. Gain Data 

    3. Analysis Data

    4. Take Desciosions

## Commands:
- **`top`** : Display and update sorted information about processes.
- **`time`** : Display the time it takes to run a command.
- **`pstack`** : Display the stack of a running process, showing the stack frames inside for ex if we have a cpp file and we build the ./a.out file , if we run pstack ./a.out it will show function main and the other functions that are called inside the main function (beltarteeb).
- **`lsof -p <ProcessID>`** : Show the Files that are used with the process , or the files that the process is using and interacting with!

