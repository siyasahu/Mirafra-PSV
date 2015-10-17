SD Card init sequence
    1. Init freq = 10 KHz
    2. Operating freq = 100 KHz
    
    Init Sequence:
        Send cmd_0 until you get 1 (100 times)
        Send cmd_1 until you get 0 (1000 times)
     
    No pull up needed on MISO or any line.
    
    
    