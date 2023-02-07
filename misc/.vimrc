"" Vim configuration file

"" Enable mouse support
set mouse=a 

"" Disable Compatibility with VI 
set nocompatible

"" Enable file type detection
filetype on 

"" Set line enumeration
set number relativenumber 

"" Add syntax highlighting
syntax on 

"" Set colorscheme
colorscheme desert 

"" Set shift width to 4 spaces
set shiftwidth=4 

"" Set tabwidth to 4 columns
set tabstop=4 

"" Use space characters instead of tabs
set expandtab 

"" Do not save backup files
set nobackup 

"" Show partial command you type in the last line of the screen 
set showcmd 

"" Show the mode you are on the last line 
set showmode  

"" Enable auto completion menu after pressing TAB
set wildmenu 

"" Make wildmenu behave like similar to Bash completion
set wildmode=list:longest 

"" Disable sounds in VIM
set visualbell 

"" Disable sounds in VIM
set t_vb= 

"" Show the matching pair of brackets
set showmatch 
