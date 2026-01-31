FROM gcc:latest
WORKDIR /usr/src/myapp
COPY myapp.cpp .
RUN g++ -o myapp myapp.cpp
CMD ["./myapp"]
