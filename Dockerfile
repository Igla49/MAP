FROM gcc:latest
WORKDIR /Desktop/MAP/MAP
COPY main.cpp .
RUN g++ -o MAP main.cpp
CMD ["./MAP"]
