### リークパターン修正ログ(2025/06/21)
`main.c`
```
int main(void)
{
	char	*line;
	int		fd;
	char	c;
	fd = 0;
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		c = *line;
		free(line);
		if (c == '\n')
			break ;
	}
	close(fd);
	return (0);
}
```
これは標準入力から、入力を受取り改行だけが来たときに終了する読み取りを終了するという実行ファイルを作成する。  
このとき、メモリーリークを確認すると`get_next_line`関数内の静的配列である`stash`が`free`されていないからだった。  
これを修正するために、`clean_stash()`関数を修正した。  
従来は
```
if (!stash[i])
  return (free(stash), NULL);
```
改行の文字だけを確認していたが、
```
if (!stash[i] && !stash[i + 1])
  return (free(stash), NULL);
```
とすることで改行後に文字があるかどうかを確認することでメモリリークを防げた。  

### セグフォパターン修正ログ (2025/6/22)
修正箇所は`for_stash`関数内  
```
	if (!stash)
		stash = ft_strdup(""); //stashにはなにか入れる。
		while (!ft_strchr(stash, '\n') && (*byte) > 0)
		{
			...
			if (!*stash)
			{
				tmp = ft_strdup((free(stash), buf));
				stash = tmp;
			}
			...
		}
```
従来は`stash`が`NULL`だったときにそのまま`ft_strchr()`関数内に流していた。  
関数に渡される`str`はNULLが入らないように設計されるべきだ。  
NULLが渡されたときにその地点がバグの原因になっていることに早期気付けることがその理由だ。  
`ft_strchr`関数修正箇所
```
char	*ft_strchr(const char *s, int c)
{
	if (!s) //この箇所を削除した。
		return ; //NULLチェックをしないことでバグの原因を早期に特定できる。
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
```