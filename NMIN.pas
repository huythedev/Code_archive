const   fi='NMIN.INP';
        fo='NMIN.OUT';
var A:array[1..10000000]of longint;
    B:array[0..10000000]of longint;
    n,res:int64;
  
procedure       docfile;
  var   i:longint;
  begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
        readln(n);
        for i:=1 to n do read(a[i]);
  end;
(*procedure       xuly;
begin
        res:=0;
        for i:=1 to n do
          begin
             res:=0;
             for i:=1 to n do
               begin
                   res:=max(res,a[i]);
                   inc(b[a[i]]);
              end;
          for i:=0 to res do
              if b[i]=0 then begin write(i);   break;  end;
              end;*)
procedure       xuly;
var 	i:longint;
begin
        res:=0;
        for i:=1 to n do inc(B[A[i]]);
	for i:=0 to 10000000 do if B[i]=0 then begin
		write(i);
		halt;
	end;
end;
begin
        docfile;
        xuly;
end.





