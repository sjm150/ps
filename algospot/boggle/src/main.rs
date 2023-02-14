use std::io::{self, Read};
use std::fmt::Write;

const SIZE: usize = 5;
const MAX_LEN: usize = 10;

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let c: usize = input.next().unwrap().parse().unwrap();

    let mut board = [[b' '; SIZE]; SIZE];

    let mut out = String::with_capacity(15 * 10 * 50);

    for _ in 0..c {
        // initialize board
        for line in &mut board {
            let bytes = input.next().unwrap().as_bytes();
            for i in 0..SIZE {
                line[i] = bytes[i];
            }
        }

        let n = input.next().unwrap().parse().unwrap();
        // initialize words
        let mut words = Vec::with_capacity(n);
        for _ in 0..n {
            words.push(input.next().unwrap().as_bytes());
        }

        // logic
        'outermost: for word in words {
            write!(out, "{} ", String::from_utf8_lossy(word)).unwrap();
                    if has_word(&board, word) {
                        writeln!(out, "YES").unwrap();
                        continue 'outermost;
                    }
            writeln!(out, "NO").unwrap();
        }
    }

    print!("{out}");
}

fn has_word(board: &[[u8; SIZE]; SIZE], word: &[u8]) -> bool {
    let mut has_suffix = [[[false; MAX_LEN]; SIZE]; SIZE];

    for i in (0..word.len()).rev() {
        compute_suffix_existence(board, &word[i..], &mut has_suffix)
    }

    for x in 0..SIZE {
        for y in 0..SIZE {
            if has_suffix[x][y][word.len() - 1] {
                return true;
            }
        }
    }

    false
}

fn compute_suffix_existence(board: &[[u8; SIZE]; SIZE], suffix: &[u8], result: &mut [[[bool; MAX_LEN]; SIZE]; SIZE]) {
    for x in 0..SIZE {
        for y in 0..SIZE {
            if suffix[0] == board[x][y] {
                let len = suffix.len();

                if len == 1 {
                    result[x][y][0] = true;
                } else {
                    for (next_x, next_y) in delta(x, y, SIZE) {
                        if result[next_x][next_y][len - 2] == true {
                            result[x][y][len - 1] = true;
                        }
                    }
                }
            }
        }
    }
}

fn delta(x: usize, y: usize, max: usize) -> Vec<(usize, usize)> {
    let mut next = Vec::with_capacity(8);

    for dx in 0..=2 {
        for dy in 0..=2 {
            if dx == 1 && dy == 1 { continue; }
            let x = (x + dx).checked_sub(1);
            let y = (y + dy).checked_sub(1);

            if let Some(x) = x {
                if let Some(y) = y {
                    if x < max && y < max {
                        next.push((x, y));
                    }
                }
            }
        }
    }

    next
}
