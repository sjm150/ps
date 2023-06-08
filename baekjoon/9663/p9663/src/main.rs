use std::io;

struct Board {
    n: usize,
    used_row: [bool; 14],
    used_col: [bool; 14],
    used_diag_lt: [bool; 27],
    used_diag_rt: [bool; 27],
}

impl Board {
    fn new(n: usize) -> Board {
        Board {
            n: n,
            used_row: [false; 14],
            used_col: [false; 14],
            used_diag_lt: [false; 27],
            used_diag_rt: [false; 27],
        }
    }

    fn used(&self, r: usize, c: usize) -> bool {
        return self.used_row[r] || self.used_col[c] || self.used_diag_lt[self.n - 1 + r - c] || self.used_diag_rt[r + c];
    }

    fn put(&mut self, r: usize, c: usize) {
        self.used_row[r] = true;
        self.used_col[c] = true;
        self.used_diag_lt[self.n - 1 + r - c] = true;
        self.used_diag_rt[r + c] = true;
    }

    fn remove(&mut self, r: usize, c: usize) {
        self.used_row[r] = false;
        self.used_col[c] = false;
        self.used_diag_lt[self.n - 1 + r - c] = false;
        self.used_diag_rt[r + c] = false;
    }
}

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();

    let mut board = Board::new(n);
    let mut num = 0;
    put_queen(0, &mut board, &mut num);
    
    println!("{}", num);
}

fn put_queen(r: usize, board: &mut Board, num: &mut usize) {
    if r == board.n {
        *num += 1;
        return;
    }

    for c in 0..board.n {
        if board.used(r, c) {
            continue;
        }
        board.put(r, c);
        put_queen(r + 1, board, num);
        board.remove(r, c);
    }
}
