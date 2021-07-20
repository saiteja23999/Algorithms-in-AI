browse :- 
        seeing(Old),      /* save for later */ 
        see(user), 
        write('Enter name of file to browse: '), read(File), 
        see(File),        /* open this file */ 
        repeat, 
        read(Data),       /* read from File */ 
        process(Data),    
        seen,             /* close File */ 
        see(Old),          /*  previous read source */ 
        !.                /* stop now */ 

process(end_of_file) :- !. 
process(Data) :-  write(Data), write('.'), nl, fail. 
