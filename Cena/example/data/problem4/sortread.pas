unit sortread;

interface

type
  ArrInt5000=record
    Src: array[1..5000]of integer;
    Count: integer;
  end;

var
  s: ArrInt5000;

implementation

var
  i: integer;

begin 
  assign(input,'4.in'); 
  reset(input);
  readln(s.Count);
  for i:=1 to s.Count do
    readln(s.Src[i]);
  close(input);
end.