FROM mcr.microsoft.com/vscode/devcontainers/cpp

RUN apt-get update && apt-get install -y \
    pipx

USER vscode

RUN pipx install norminette
