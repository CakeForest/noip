program lamp;
const	maxn=400;
	maxw=400;
type	li=array [0..maxw] of longint;
	fl=array [0..maxw,0..maxn] of integer;
var	light:array [0..maxn] of li;
	light1:li;
	flight:array [0..maxn] of fl;
	flight1:fl;
	f,w,p,l,v:array [0..maxn] of longint;
	n,s:longint;

function min(a,b:longint):longint;
begin
	if a<b then min:=a else min:=b;
end;

procedure init;
var	i:longint;
begin
	assign(input,'lamp.in');
	reset(input);
	read(n);
	for i:=1 to n do read(f[i],w[i],p[i],l[i]);
	close(input);
end;

procedure treedp;
var	i,j,k,t,q:longint;
begin
	fillchar(flight,sizeof(flight),0);
	for i:=0 to n do for j:=0 to maxw do light[i,j]:=-1;
	for i:=1 to n do begin light[i,w[i]]:=l[i]; flight[i,w[i],i]:=w[i]; end;
	for k:=n downto 2 do
	begin
		t:=f[k];
		light1:=light[t];
		flight1:=flight[t];
		for i:=min(p[t],p[k]+w[k]) downto w[k] do
		begin
			q:=light[k,i];
			if q<>-1 then
			for j:=p[t]+w[t]-i downto 0 do
				if (light[t,j]<>-1) and (light1[j+i]<light[t,j]+q)
				then begin
					light1[j+i]:=light[t,j]+q;
					flight1[j+i]:=flight[t,j];
					flight1[j+i,k]:=i;
				end;
		end;
		light[t]:=light1;
		flight[t]:=flight1;
	end;
end;

procedure find(k,t:longint);
var	i:longint;
begin
	if v[k]<>1 then begin v[k]:=1; inc(s); end;
	for i:=k+1 to n do if flight[k,t,i]<>0 then find(i,flight[k,t,i]);
end;


procedure print;
var	m,i,t:longint;
begin
	fillchar(v,sizeof(v),0);
	s:=0;
	m:=0;
	for i:=0 to p[1]+w[1] do if m<light[1,i] then begin m:=light[1,i]; t:=i; end;
	find(1,t);
	for i:=1 to n do if (v[i]=0) and (w[i]=0) then begin v[i]:=1; inc(s); end;
	assign(output,'lamp.out');
	rewrite(output);
	writeln(s,' ',m);
	for i:=1 to n do
		if v[i]=1 then begin
			if s<>1 then begin write(i,' '); dec(s); end
				else writeln(i);
		end;
	close(output);
end;

begin
	init;
	treedp;
	print;
end.