browse :- 
        seeing(Old),      
        see(user), 
        write('Enter name of file to browse: '), read(File), 
        see(File), 
        repeat, 
        read(Data), 
        process(Data),    
        seen,       
        see(Old)    
        !.          
