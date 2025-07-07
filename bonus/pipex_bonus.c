#include "pipex_bonus.h"

//プロセス起動時の3変数
int	main(int ac, char *av[], char *ep[])
{
	//異常終了→EXIT_FAILURE
	//正常終了→最後の子プロセスの終了コード
	t_pipex px;

	init_pipex(&px, ac, av, ep);
	parse_commands(&px, av, 2 + px.mode);

}

int	pipex_init(t_pipex *px, int ac, char *av[], char *ep[])
{
	//最初にモードを決定
	// if モードnormal
		//mode = 0
		//cmd_count = argc - 3
		//limiter = NULL
		//open_input()

	// if モードhear_doc
		//mode = 1
		//cmd_count = argc - 4
		//limiter = get_next_lineでテキストを取得
		//here_doc_input()
	
	//失敗時はfree_pipex()を
}

int	parse_commands(t_pipex *px, char *av[], int first_cmd_i)
{
	//px->cmds[k]にargvを格納
	//index k: first_cmd_iからcmd_countでavからpx->cmds[k]にデータを格納
}

int	resolve_path(t_cmd *cmd, char *ep[])
{
	//cmd->pathを確定
	//envp内のPATH=を走査してaccess(full_path, X_OK)で検証。
	//見つからなければ、cmd->path = NULLで子プロセス側が
	//"command not found"を標準エラー出力して127終了
	//malloc失敗時は-1
}

int	open_input(t_pipex *px, const char *file)
{
	//px->in_fdを設定
	//存在しない場合はerror_exitを出力
}

int open_output(t_pipex *px, const char *file)
{
	//px->out_fdを設定
}

int	here_doc_input(t_pipex *px, const char *limiter)
{
	//limiter = "LIMITER"
	//リミッタ行までのSTDINをin_fdに読み込む
	//while((line = get_next_line(STDIN_FILENO)))
	//if (!ft_strncmp(line, limiter))
}

int	create_pipes(t_pipex *px)
{
	//(N - 1)本のpipe()を生成し、px->pipesへ格納
	//px->pipes = malloc(sizeof(int *) * (px->cmd_count - 1))
	//各px->pipex[i] = malloc(sizeof(int) * 2)
	//失敗時は既成パイプを閉じてreturn -1
}

void	select_fd(const t_pipex *px, int idx)
{
	//実行中のコマンド番号idx
	//子プロセスで不要なFDをすべて閉じる

	//書き端：dup2(idx == 0 ? in_fd : pipes[idx][1], STDOUT_FILENO)
	//読み端：dup2(idx == 0 ? in_fd : pipes[idx - 1][0], STDIN_FILENO)
	//それ以外のFD(全パイプ+in_fd/out_fd)は必ずclose
}

void	child_exec(t_pipex *px, int idx)
{
	//dup2, execveを失敗時にerror_exit
}

int	launch_children(t_pipex *px)
{
	//初期化済みpxが与えられる
	//forkをN回、各子でchild_exec()
}

int	wait_children(t_pipex *px)
{
	//px->pidsを使う
	//全子をwaitpid、最後の子のstatusを返す
}

void	free_pipex(t_pipex *px)
{
	//動的領域を全部開放した後、closeも行う
}

void	error_exit(t_pipex *px, char *msg)
{
	//perror(msg)→free_pipex()→exit(EXIT_FAILURE)
}