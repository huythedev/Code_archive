Const   fi = 'KXVD1.INP';
        fo = 'KXVD1.OUT';
Var     St1, St2: String;
Procedure       docfile;
   Begin
       assign(input,fi);        reset(input);
       assign(output,fo);       rewrite(output);
       Readln(St1);
       Readln(St2);
   End;
procedure       xuly;
   Begin
       if Length(St1)>Length(St2) then writeln(St1)
       else writeln(St2);
   End;
Begin
    docfile;
    xuly;
End.