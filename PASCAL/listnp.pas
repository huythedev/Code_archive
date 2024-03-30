const   fi='listnp.inp';
        fo='listnp.out';
        max=20;
var     n:byte;
        b:array[0..max] of byte;
        f:text;
procedure       input;
    begin
        assign(f,fi); reset(f);
        readln(f,n);
        close(f);
    end;
procedure       PrintResult;
   var i:byte;
   begin
       for i:=1 to n do write(f,b[i]);
       writeln(f);
   end;
procedure Attempt(i: Integer); {Th? cÿc cÿch ch?n b[i]}
var
  j: Integer;
begin
  for j := 0 to 1 do {X,t cÿc giÿ tr? c› th? gÿn cho b[i], v?i m?i giÿ tr? d›}
    begin
      b[i] := j; {Th? d?t b[i]}
      if i = n then PrintResult {N?u i = n th? in k?t qu?}
      else Attempt(i + 1);{N?u i chua ph?i l. ph?n t? cu?i th? t?m ti?p b[i+1]}
    end;
end;
begin
    input;
    assign(f,fo);    rewrite(f);
    attempt(1);
    close(f);
end.
