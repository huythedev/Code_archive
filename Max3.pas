const fi='Max3.INP';
      fo='Max3.OUT';

var A,B,c,m: longint;

   g,f:text;
 Begin
    assign(f,fi);reset(f);
    assign(g,fo);rewrite(g);
   read(f,a,b,c);
   m:=a ;

   if m<b then m:=b;
    if m<c then m:=c;
    write(g,m);
 close(g);
end.
