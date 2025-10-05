class Solution:
    def ratInMaze(self, maze):
        n=len(maze)
        visited=[[False]*n for _ in range(n)]
        directions=[('D',1,0),('U',-1,0),('L',0,-1),('R',0,1)]
        res=[]
        def check(x,y):
            return 0<=x<n and 0<=y<n and maze[x][y]==1 and not visited[x][y]
        def backtrack(x,y,path):
            if x==n-1 and y==n-1:
                res.append(path)
                return
            for step,dx,dy in directions:
                nx=x+dx
                ny=y+dy
                if check(nx,ny):
                    visited[nx][ny]=True
                    backtrack(nx,ny,path+step)
                    visited[nx][ny]=False
        if maze[0][0]==1:
            visited[0][0]=True
            backtrack(0,0,'')
        return sorted(res)