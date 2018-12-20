var
  i,x,n: integer;

begin 
  assign(input,'3.in');
  reset(input);
  assign(output,'3.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do begin 
    readln(x);
    writeln(x);
  end;
  close(input);
  close(output);
end.