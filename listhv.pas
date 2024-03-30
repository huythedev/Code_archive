const   fi='listhv.inp';
        fo='listhv.out';
        max=20;
var     n:byte;
        c,x:array[1..max] of byte;
        f:text;
procedure       docfile;
    begin
        assign(input,fi); reset(input);
        readln(n);
    end;
procedure       PrintResult;
   var i:byte;
   begin
       for i:=1 to n do
          write(x[i],' ');
       writeln();
   end;
procedure try(i: Integer); {Thu chon x[i]}
var
  j: Integer;
begin
  for j := 1 to n do {cac de xuat cho x[i]}
    if c[j]=0 then
    begin
      x[i] := j; {Thu dat x[i]}
      c[j]:=1;
      if i = n then PrintResult {in ket qua}
      else try(i + 1);{Neu i chua phai ptu cuoi cung thi tim tiep x[i+1]}
      c[j]:=0;
    end;
end;
begin
    docfile;
    assign(output,fo);    rewrite(output);
    try(1);
end.

