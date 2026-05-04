/**
 * @file beluga_neighbor_list.hpp
 *
 * @brief Manages a list of Beluga neighbors
 *
 * @date 1/30/25
 *
 * @author Tom Schmitz <tschmitz@andrew.cmu.edu>
 */

#ifndef BELUGA_SERIAL_BELUGA_NEIGHBOR_LIST_HPP
#define BELUGA_SERIAL_BELUGA_NEIGHBOR_LIST_HPP

#include <beluga/beluga_frame.hpp>
#include <exception>
#include <fstream>
#include <map>
#include <string>
#include <vector>

namespace BelugaSerial {

/// Exception class for Beluga entry errors
class BelugaEntryError : std::exception {
  public:
    explicit BelugaEntryError(const char *msg) { _msg = msg; }

    [[nodiscard]] const char *what() const noexcept override {
        return _msg.c_str();
    }

  private:
    std::string _msg;
};

/// Class representing a neighbor in the Beluga network
class BelugaNeighbor {
  public:
    BelugaNeighbor() = default;

    explicit BelugaNeighbor(const BelugaFrame::NeighborUpdate &neighbor);

    BelugaNeighbor(const BelugaNeighbor &) = default;
    BelugaNeighbor(BelugaNeighbor &&) = default;
    ~BelugaNeighbor() = default;

    BelugaNeighbor &operator=(const BelugaNeighbor &copy) = default;

    [[nodiscard]] uint16_t id() const noexcept;
    [[nodiscard]] double range() const noexcept;
    [[nodiscard]] int8_t rssi() const noexcept;
    [[nodiscard]] int64_t time() const noexcept;
    [[nodiscard]] uint32_t exchange() const noexcept;

    // ---------------- Diagnostic getters ----------------
    [[nodiscard]] uint16_t maxNoise() const noexcept;
    [[nodiscard]] uint16_t firstPathAmp1() const noexcept;
    [[nodiscard]] uint16_t firstPathAmp2() const noexcept;
    [[nodiscard]] uint16_t firstPathAmp3() const noexcept;
    [[nodiscard]] uint16_t stdNoise() const noexcept;
    [[nodiscard]] uint16_t maxGrowthCIR() const noexcept;
    [[nodiscard]] uint16_t rxPreamCount() const noexcept;
    [[nodiscard]] uint16_t firstPath() const noexcept;

    // ---------------- DS-TWR timestamp getters ----------------
    [[nodiscard]] uint32_t poll_tx_ts() const noexcept;
    [[nodiscard]] uint32_t poll_rx_ts() const noexcept;
    [[nodiscard]] uint32_t resp_tx_ts() const noexcept;
    [[nodiscard]] uint32_t resp_rx_ts() const noexcept;
    [[nodiscard]] uint32_t final_tx_ts() const noexcept;
    [[nodiscard]] uint32_t final_rx_ts() const noexcept;
    [[nodiscard]] uint32_t report_tx_ts() const noexcept;
    [[nodiscard]] uint32_t report_rx_ts() const noexcept;

    [[nodiscard]] bool updated() const noexcept;
    void updated(bool update);

    void update(const BelugaFrame::NeighborUpdate &neighbor);

  private:
    uint16_t _id = 0;
    double _range = 0.0;
    int8_t _rssi = 0;
    int64_t _time = 0;
    uint32_t _exchange = 0;
    bool _updated = false;

    // ---------------- Diagnostic fields ----------------
    uint16_t _maxNoise;
    uint16_t _firstPathAmp1;
    uint16_t _firstPathAmp2;
    uint16_t _firstPathAmp3;
    uint16_t _stdNoise;
    uint16_t _maxGrowthCIR;
    uint16_t _rxPreamCount;
    uint16_t _firstPath;

    // ---------------- DS-TWR timestamps ----------------
    uint32_t _poll_tx_ts;
    uint32_t _poll_rx_ts;
    uint32_t _resp_tx_ts;
    uint32_t _resp_rx_ts;
    uint32_t _final_tx_ts;
    uint32_t _final_rx_ts;
    uint32_t _report_tx_ts;
    uint32_t _report_rx_ts;
};

/// Class representing a list of Beluga neighbors
class BelugaNeighborList {
  public:
    BelugaNeighborList() = default;
    ~BelugaNeighborList() = default;

    void update(const std::vector<BelugaFrame::NeighborUpdate> &updates);
    void remove(uint32_t node_id);
    void get_updates(std::vector<BelugaNeighbor> &updates);
    void get_neighbors(std::vector<BelugaNeighbor> &neighbors);
    void clear() noexcept;

    [[nodiscard]] bool neighbor_updates() const noexcept;
    [[nodiscard]] bool range_updates() const noexcept;

  private:
    std::map<uint16_t, BelugaNeighbor> _list;
    bool _neighbors_update = false;
    bool _range_update = false;
};

} // namespace BelugaSerial

#endif // BELUGA_SERIAL_BELUGA_NEIGHBOR_LIST_HPP