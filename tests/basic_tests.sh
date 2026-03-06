#!/bin/bash

echo "Running cshell tests..."

echo "Test 1: command execution"
echo "ls" | ./cshell

echo "Test 2: pipes"
echo "echo hello | grep hello" | ./cshell

echo "Test 3: redirection"
echo "echo hello > test.txt" | ./cshell

echo "Tests finished"
