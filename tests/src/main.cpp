/*
** EPITECH PROJECT, 2019
** test component
** File description:
** arcade
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void) {
  cr_redirect_stdout();
  cr_redirect_stderr();
}

Test(first, init_game, .init = redirect_all_stdout) {
  cr_assert_stdout_eq_str("test\n");
}
