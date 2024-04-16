var
  k, n, i, res, tmp: int64;

begin
  res := 1;

  readln(k, n);

  for i := 2 to n do
  begin
    tmp := round(exp(ln(i) * (2 * k))) mod 10;
    res := (res + tmp) mod 10;
  end;

  writeln(res);
end.
