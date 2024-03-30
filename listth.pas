const fi='listth.INP';
      fo='listth.OUT';
var n,k:byte;i,j:integer;
    a:array[0..100] of byte;
procedure kq;
var x:integer;
begin
        for i:=1 to k do write(a[i],' ');
        writeln;
end;
procedure hv(i:longint);
var j:integer;
begin
    for j:=a[i-1]+1 to n do
        begin
                a[i]:=j;
                if i=k then kq else hv(i+1);
        end;
end;
begin
    assign(input,fi);reset(input);
    assign(output,fo);rewrite(output);
    read(n,k); a[0]:=0;
    hv(1);
end.
