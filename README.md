<p align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/get_next_linem.png" height="150" alt="42 get_next_line Badge"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/42-Project-blue" height="32"/>
  <img src="https://img.shields.io/github/languages/code-size/Ego8316/get_next_line?color=5BCFFF" height="32"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Linux-0a97f5?style=for-the-badge&logo=linux&logoColor=white" height="32"/>
  <img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white" height="32"/>
  <img src="https://img.shields.io/badge/WSL-0a97f5?style=for-the-badge&logo=linux&logoColor=white" height="32"/>
</p>

# get_next_line

### 🎓 42 School – Final Grade: **125/100**

Line-by-line file reader that handles arbitrary buffer sizes, EOF detection, and multiple file descriptors (bonus).

---

## 📦 Features
- Reads one line per call, including the trailing newline when present.
- Works with any `BUFFER_SIZE` (set at compile time).
- Bonus: independent stash per FD for interleaved reads.
- Minimal helper set: `ft_memset`, `ft_memmove`, `ft_strlen_null`, `ft_char_in_str`.

---

## 🛠️ Building
```bash
git clone https://github.com/Ego8316/get_next_line.git
cd get_next_line
# Non-bonus build
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
# Bonus build (multi-FD)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

---

## 🚀 Usage
```c
#include "get_next_line.h"

int	main(void)
{
	int   fd = open("file.txt", O_RDONLY);
	char  *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		write(1, line, ft_strlen_null(line));
		free(line);
	}
	close(fd);
	return (0);
}
```
Adjust `BUFFER_SIZE` at compile time as needed.

---

## ✅ Testing
- Vary `BUFFER_SIZE` values and file sizes (small, large, empty).
- Bonus: interleave reads on several FDs to confirm stash isolation.
- Norm compliance: `norminette` at the repository root.

---

## 📄 License
MIT License — see `LICENSE` for details.
