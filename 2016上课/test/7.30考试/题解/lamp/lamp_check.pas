var	f,w,p,l,a,v,s:array [0..400] of longint;
	k,m,n,i:longint;
begin
	assign(output,'result.dat');
	rewrite(output);
	writeln('error!');
	close(output);

	assign(input,'lamp.ans');
	reset(input);
	read(m);
	read(m);
	close(input);

	assign(input,'lamp.out');
	reset(input);
	read(k);
	read(k);
	close(input);

	if k<>m then halt;

	assign(input,'lamp.in');
	reset(input);
	read(n);
	for i:=1 to n do read(f[i],w[i],p[i],l[i]);
	close(input);

	assign(input,'lamp.out');
	reset(input);
	read(m);
	read(k);
	fillchar(v,sizeof(v),0);
	for i:=1 to m do begin read(a[i]); v[a[i]]:=1; end;
	v[0]:=1;
	for i:=m downto 1 do if v[f[a[i]]]=0 then halt;
	fillchar(s,sizeof(s),0);
	for i:=m downto 1 do inc(s[f[a[i]]],l[a[i]]+s[a[i]]);
	if s[0]<>k then halt;
	fillchar(s,sizeof(s),0);
	for i:=m downto 1 do inc(s[f[a[i]]],w[a[i]]+s[a[i]]);
	for i:=1 to m do if s[i]>p[i] then halt;
	close(input);

	assign(output,'result.dat');
	rewrite(output);
	writeln('right!');
	close(output);
end.
