Const   fi = 'MAX2.INP';
        fo = 'MAX2.OUT';
Var     a,b: longint;
Procedure       docfile;
   var i:longint;
   begin
       assign(input,fi); reset(input);
       assign(output,fo); rewrite(output);
       Readln(a,b);
   end;
Procedure       xuly;
   begin
       if a>b then writeln(a)
       else writeln(b);
   end;

Begin
    docfile;
    xuly;
End.