use std::io::{self, Read};
use std::fmt::Write;

const SIZE: usize = 5;

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
            for x in 0..SIZE as isize {
                for y in 0..SIZE as isize {
                    if has_word(&board, x, y, word) {
                        writeln!(out, "YES").unwrap();
                        continue 'outermost;
                    }
                }
            }
            writeln!(out, "NO").unwrap();
        }
    }

    print!("{out}");
}

fn has_word(board: &[[u8; SIZE]; SIZE], x: isize, y: isize, word: &[u8]) -> bool {
    if word[0] != board[x as usize][y as usize] {
        false
    } else if word.len() == 1 {
        true
    } else {
        for dx in -1..=1 {
            for dy in -1..=1 {
                if dx == 0 && dy == 0 { continue; }
                let new_x = x + dx;
                if new_x < 0 || SIZE <= new_x as usize { continue; }
                let new_y = y + dy;
                if new_y < 0 || SIZE <= new_y as usize { continue; }

                if has_word(board, new_x, new_y, &word[1..]) {
                    return true;
                }
            }
        }
        false
    }
}
